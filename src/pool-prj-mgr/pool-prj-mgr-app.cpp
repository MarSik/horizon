#include "pool-prj-mgr-app.hpp"
#include "pool-prj-mgr-app_win.hpp"
#include <glibmm/miscutils.h>
#include <fstream>
#include "util/util.hpp"
#include "util/recent_util.hpp"
#include <git2.h>
#include <curl/curl.h>
#include "nlohmann/json.hpp"
#include "close_utils.hpp"
#include "pool/pool_manager.hpp"
#include "preferences/preferences_window.hpp"
#include "preferences/preferences_provider.hpp"
#include "widgets/about_dialog.hpp"
#include "widgets/log_window.hpp"
#include "logger/logger.hpp"
#include "widgets/log_view.hpp"
#include "util/zmq_helper.hpp"

#ifdef G_OS_WIN32
#include <winsock2.h>
#include "util/win32_undef.hpp"
#endif

namespace horizon {

PoolProjectManagerApplication::PoolProjectManagerApplication()
    : Gtk::Application("org.horizon_eda.HorizonEDA.pool_prj_mgr", Gio::APPLICATION_HANDLES_OPEN),
      sock_broadcast(zctx, ZMQ_PUB)
{
    sock_broadcast.bind("tcp://127.0.0.1:*");
    char ep[1024];
    size_t sz = sizeof(ep);
    sock_broadcast.getsockopt(ZMQ_LAST_ENDPOINT, ep, &sz);
    sock_broadcast_ep = ep;
}

const std::string &PoolProjectManagerApplication::get_ep_broadcast() const
{
    return sock_broadcast_ep;
}

void PoolProjectManagerApplication::send_json(int pid, const json &j)
{
    std::string s = j.dump();
    zmq::message_t msg(s.size() + 5);
    memcpy(msg.data(), &pid, 4);
    memcpy(((uint8_t *)msg.data()) + 4, s.c_str(), s.size());
    auto m = (char *)msg.data();
    m[msg.size() - 1] = 0;
    zmq_helper::send(sock_broadcast, msg);
}

Glib::RefPtr<PoolProjectManagerApplication> PoolProjectManagerApplication::create()
{
    return Glib::RefPtr<PoolProjectManagerApplication>(new PoolProjectManagerApplication());
}

PoolProjectManagerAppWindow *PoolProjectManagerApplication::create_appwindow()
{
    auto appwindow = PoolProjectManagerAppWindow::create(this);

    // Make sure that the application runs for as long this window is still
    // open.
    add_window(*appwindow);

    // Gtk::Application::add_window() connects a signal handler to the window's
    // signal_hide(). That handler removes the window from the application.
    // If it's the last window to be removed, the application stops running.
    // Gtk::Window::set_application() does not connect a signal handler, but is
    // otherwise equivalent to Gtk::Application::add_window().

    // Delete the window when it is hidden.
    appwindow->signal_hide().connect(
            sigc::bind(sigc::mem_fun(*this, &PoolProjectManagerApplication::on_hide_window), appwindow));

    return appwindow;
}

void PoolProjectManagerApplication::on_activate()
{
    // The application has been started, so let's show a window.
    auto appwindow = create_appwindow();
    appwindow->present();
}

std::string PoolProjectManagerApplication::get_config_filename()
{
    return Glib::build_filename(get_config_dir(), "pool-project-manager.json");
}

void PoolProjectManagerApplication::load_from_config(const std::string &config_filename)
{
    json j = load_json_from_file(config_filename);
    if (j.count("part_favorites")) {
        const json &o = j.at("part_favorites");
        for (auto it = o.cbegin(); it != o.cend(); ++it) {
            part_favorites.push_back(it.value().get<std::string>());
        }
    }
    pool_doc_info_bar_dismissed = j.value("pool_doc_info_bar_dismissed", false);
    recent_from_json(recent_items, j);
}

void PoolProjectManagerApplication::on_startup()
{
    // Call the base class's implementation.
    Gtk::Application::on_startup();

    git_libgit2_init();
#ifdef G_OS_WIN32
    {
        std::string cert_file = Glib::build_filename(horizon::get_exe_dir(), "ca-bundle.crt");
        git_libgit2_opts(GIT_OPT_SET_SSL_CERT_LOCATIONS, cert_file.c_str(), NULL);
    }
#endif
    curl_global_init(CURL_GLOBAL_ALL);

    add_action("preferences", [this] { show_preferences_window(); });
    add_action("logger", [this] { show_log_window(); });
    add_action("quit", sigc::mem_fun(*this, &PoolProjectManagerApplication::on_action_quit));
    add_action("new_window", sigc::mem_fun(*this, &PoolProjectManagerApplication::on_action_new_window));
    add_action("about", sigc::mem_fun(*this, &PoolProjectManagerApplication::on_action_about));
    add_action("view_log", [this] { show_log_window(); });
    set_accel_for_action("app.quit", "<Ctrl>Q");

    recent_items.clear();
    if (Glib::file_test(get_config_filename(), Glib::FILE_TEST_IS_REGULAR)) {
        load_from_config(get_config_filename());
    }
    else {
        std::vector<std::string> old_configs;
        old_configs.push_back(Glib::build_filename(get_config_dir(), "pool-manager.json"));
        old_configs.push_back(Glib::build_filename(get_config_dir(), "project-manager.json"));
        for (const auto &it : old_configs) {
            if (Glib::file_test(it, Glib::FILE_TEST_IS_REGULAR))
                load_from_config(it);
        }
    }

    preferences.load();
    PreferencesProvider::get().set_prefs(preferences);
    preferences.signal_changed().connect([this] {
        json j;
        j["op"] = "preferences";
        j["preferences"] = preferences.serialize();
        send_json(0, j);
    });

    log_window = new LogWindow();
    log_dispatcher.set_handler([this](const auto &it) { log_window->get_view()->push_log(it); });
    Logger::get().set_log_handler([this](const Logger::Item &it) { log_dispatcher.log(it); });

    Gtk::IconTheme::get_default()->add_resource_path("/org/horizon-eda/horizon/icons");
    Gtk::Window::set_default_icon_name("horizon-eda");

    auto cssp = Gtk::CssProvider::create();
    cssp->load_from_resource("/org/horizon-eda/horizon/global.css");
    Gtk::StyleContext::add_provider_for_screen(Gdk::Screen::get_default(), cssp, 700);

    signal_shutdown().connect(sigc::mem_fun(*this, &PoolProjectManagerApplication::on_shutdown));
}

PreferencesWindow *PoolProjectManagerApplication::show_preferences_window(guint32 timestamp)
{
    if (!preferences_window) {
        preferences_window = new PreferencesWindow(preferences);

        preferences_window->signal_hide().connect([this] {
            delete preferences_window;
            preferences_window = nullptr;
            preferences.save();
        });
    }
    preferences_window->present(timestamp);
    return preferences_window;
}

LogWindow *PoolProjectManagerApplication::show_log_window(guint32 timestamp)
{
    log_window->present(timestamp);
    return log_window;
}

void PoolProjectManagerApplication::on_shutdown()
{
    auto config_filename = get_config_filename();

    json j;
    {
        json k;
        for (const auto &it : part_favorites) {
            k.push_back((std::string)it);
        }
        j["part_favorites"] = k;
    }
    for (const auto &it : recent_items) {
        j["recent"][it.first] = it.second.to_unix();
    }
    j["pool_doc_info_bar_dismissed"] = pool_doc_info_bar_dismissed;
    save_json_to_file(config_filename, j);
}

void PoolProjectManagerApplication::on_open(const Gio::Application::type_vec_files &files,
                                            const Glib::ustring & /* hint */)
{

    // The application has been asked to open some files,
    // so let's open a new view for each one.
    PoolProjectManagerAppWindow *appwindow = nullptr;
    auto windows = get_windows();
    if (windows.size() > 0)
        appwindow = dynamic_cast<PoolProjectManagerAppWindow *>(windows[0]);

    if (!appwindow)
        appwindow = create_appwindow();

    for (const auto &file : files)
        appwindow->open_file_view(file);

    appwindow->present();
}

void PoolProjectManagerApplication::open_pool(const std::string &pool_json, ObjectType type, const UUID &uu,
                                              guint32 timestamp)
{
    PoolProjectManagerAppWindow *appwindow = nullptr;
    for (auto ws : get_windows()) {
        auto wi = dynamic_cast<PoolProjectManagerAppWindow *>(ws);
        if (wi && wi->get_filename() == pool_json) {
            appwindow = wi;
            break;
        }
    }
    if (!appwindow)
        appwindow = create_appwindow();
    appwindow->open_pool(pool_json, type, uu);
    appwindow->present(timestamp);
}

void PoolProjectManagerApplication::on_hide_window(Gtk::Window *window)
{
    delete window;
}

void PoolProjectManagerApplication::on_action_quit()
{
    // Gio::Application::quit() will make Gio::Application::run() return,
    // but it's a crude way of ending the program. The window is not removed
    // from the application. Neither the window's nor the application's
    // destructors will be called, because there will be remaining reference
    // counts in both of them. If we want the destructors to be called, we
    // must remove the window from the application. One way of doing this
    // is to hide the window. See comment in create_appwindow().
    auto windows = dynamic_cast_vector<PoolProjectManagerAppWindow *>(get_windows());
    std::map<std::string, std::map<UUID, std::string>> files;
    std::map<std::string, PoolProjectManagerAppWindow *> files_windows;
    for (auto win : windows) {
        if (win->get_filename().size())
            files_windows[win->get_filename()] = win;
    }

    bool need_dialog = false;
    for (auto it : files_windows) {
        auto win = it.second;
        auto filename = it.first;
        auto pol = win->get_close_policy();
        if (!pol.can_close) {
            Gtk::MessageDialog md(*get_active_window(), "Can't close right now", false /* use_markup */,
                                  Gtk::MESSAGE_ERROR, Gtk::BUTTONS_OK);
            md.set_secondary_text(pol.reason);
            md.run();
            return;
        }
        auto &fis = files[filename];
        for (const auto &it_proc : pol.procs_need_save) {
            need_dialog = true;
            fis[it_proc] = win->get_proc_filename(it_proc);
        }
    }

    if (need_dialog) {
        ConfirmCloseDialog dia(get_active_window());
        dia.set_files(files);
        auto r = dia.run();
        if (r == ConfirmCloseDialog::RESPONSE_NO_SAVE || r == ConfirmCloseDialog::RESPONSE_SAVE) {
            auto files_from_dia = dia.get_files();
            for (const auto &it : files_from_dia) {
                auto win = files_windows.at(it.first);
                win->prepare_close();
                if (r == ConfirmCloseDialog::RESPONSE_SAVE) {
                    for (const auto &it2 : it.second) {
                        win->process_save(it2);
                    }
                }
                auto procs = win->get_processes();
                for (auto proc : procs) {
                    win->process_close(proc.first);
                }
                win->wait_for_all_processes();
                if (!win->really_close_pool_or_project()) {
                    Gtk::MessageDialog md(*get_active_window(), "Couldn't close", false /* use_markup */,
                                          Gtk::MESSAGE_ERROR, Gtk::BUTTONS_OK);
                    md.run();
                }
                win->hide();
            }

            quit();
        }
        else {
            return;
        }
    }
    else {
        for (auto win : windows) {
            win->prepare_close();
            auto procs = win->get_processes();
            for (auto &it : procs) {
                win->process_close(it.first);
            }
            win->wait_for_all_processes();
            if (!win->really_close_pool_or_project()) {
                Gtk::MessageDialog md(*get_active_window(), "Couldn't close", false /* use_markup */,
                                      Gtk::MESSAGE_ERROR, Gtk::BUTTONS_OK);
                md.run();
            }
            win->hide();
        }
        quit();
    }
}
void PoolProjectManagerApplication::on_action_new_window()
{
    auto appwin = create_appwindow();
    appwin->present();
}

void PoolProjectManagerApplication::on_action_about()
{
    AboutDialog dia;
    auto win = get_active_window();
    if (win)
        dia.set_transient_for(*win);
    dia.run();
}

Preferences &PoolProjectManagerApplication::get_preferences()
{
    return preferences;
}
} // namespace horizon
