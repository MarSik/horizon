#include "prj-mgr_views.hpp"
#include "pool-prj-mgr/pool-prj-mgr-app_win.hpp"
#include "pool-prj-mgr/pool-prj-mgr-app.hpp"
#include "project/project.hpp"
#include "pool/pool_manager.hpp"
#include "nlohmann/json.hpp"
#include "part_browser/part_browser_window.hpp"
#include "widgets/project_meta_editor.hpp"
#include "block/block.hpp"
#include "pool/pool_cache_status.hpp"

namespace horizon {

PoolProjectManagerViewCreateProject::PoolProjectManagerViewCreateProject(const Glib::RefPtr<Gtk::Builder> &builder,
                                                                         class PoolProjectManagerAppWindow *w)
    : win(w)
{
    builder->get_widget("create_project_path_chooser", project_path_chooser);
    builder->get_widget("create_project_dir_label", project_dir_label);
    builder->get_widget("create_project_pool_combo", project_pool_combo);

    Gtk::Box *meta_box;
    builder->get_widget("new_project_meta_box", meta_box);
    meta_editor = Gtk::manage(new ProjectMetaEditor(meta_values));
    meta_box->pack_start(*meta_editor, false, false, 0);
    meta_editor->set_row_spacing(20);
    meta_editor->show();
    meta_editor->signal_changed().connect(sigc::mem_fun(*this, &PoolProjectManagerViewCreateProject::update));
    project_pool_combo->signal_changed().connect(sigc::mem_fun(*this, &PoolProjectManagerViewCreateProject::update));
    project_path_chooser->signal_file_set().connect(sigc::mem_fun(*this, &PoolProjectManagerViewCreateProject::update));
}

void PoolProjectManagerViewCreateProject::clear()
{
    meta_editor->clear();
    meta_editor->preset();
    project_dir_label->set_text("");
    project_path_chooser->unselect_all();
}

void PoolProjectManagerViewCreateProject::populate_pool_combo()
{
    project_pool_combo->remove_all();
    for (const auto &it : PoolManager::get().get_pools()) {
        if (it.second.enabled)
            project_pool_combo->append((std::string)it.second.uuid, it.second.name);
    }
    project_pool_combo->set_active(0);
}

std::pair<bool, std::string> PoolProjectManagerViewCreateProject::create()
{
    bool r = false;
    std::string s;
    try {
        Project prj(UUID::random());
        prj.base_path =
                Glib::build_filename(project_path_chooser->get_file()->get_path(), meta_values.at("project_name"));
        auto pool_uuid = static_cast<std::string>(project_pool_combo->get_active_id());

        s = prj.create(meta_values, pool_uuid, PoolManager::get().get_by_uuid(pool_uuid)->default_via);
        r = true;
    }
    catch (const std::exception &e) {
        r = false;
        Gtk::MessageDialog md(*win, "Error creating project", false /* use_markup */, Gtk::MESSAGE_ERROR,
                              Gtk::BUTTONS_OK);
        md.set_secondary_text(e.what());
        md.run();
    }
    catch (const Glib::Error &e) {
        r = false;
        Gtk::MessageDialog md(*win, "Error creating project", false /* use_markup */, Gtk::MESSAGE_ERROR,
                              Gtk::BUTTONS_OK);
        md.set_secondary_text(e.what());
        md.run();
    }
    return {r, s};
}

void PoolProjectManagerViewCreateProject::update()
{
    bool valid = true;
    if (meta_values.at("project_name").size() == 0)
        valid = false;
    if (meta_values.at("project_title").size() == 0)
        valid = false;
    if (project_path_chooser->get_filenames().size() == 0)
        valid = false;
    if (project_pool_combo->get_active_row_number() == -1)
        valid = false;
    if (valid) {
        auto base_path = project_path_chooser->get_file()->get_path();
        auto dir = Glib::build_filename(base_path, meta_values.at("project_name"));
        project_dir_label->set_text(dir);
    }
    else {
        project_dir_label->set_text("");
    }
    signal_valid_change().emit(valid);
}

PoolProjectManagerViewProject::PoolProjectManagerViewProject(const Glib::RefPtr<Gtk::Builder> &builder,
                                                             PoolProjectManagerAppWindow *w)
    : win(w)
{
    builder->get_widget("button_top_schematic", button_top_schematic);
    builder->get_widget("button_board", button_board);
    builder->get_widget("button_part_browser", button_part_browser);
    builder->get_widget("button_project_pool", button_project_pool);
    builder->get_widget("label_project_title", label_project_title);
    builder->get_widget("label_project_author", label_project_author);
    builder->get_widget("label_project_directory", label_project_directory);
    builder->get_widget("pool_cache_status_label", pool_cache_status_label);

    Gtk::Button *open_button;
    builder->get_widget("prj_open_dir_button", open_button);
    open_button->signal_clicked().connect([this] {
        auto uri = Gio::File::create_for_path(Glib::path_get_dirname(win->project_filename))->get_uri();
        Gio::AppInfo::launch_default_for_uri(uri);
    });

    Gtk::Button *edit_button;
    builder->get_widget("prj_edit_meta_button", edit_button);
    edit_button->signal_clicked().connect([this] {
        if (auto proc = win->find_top_schematic_process()) {
            win->app->send_json(proc->proc->get_pid(), {{"op", "edit-meta"}});
        }
        else {
            open_top_schematic();
            if (auto proc2 = win->find_top_schematic_process()) {
                proc2->signal_ready().connect([this, proc2] {
                    win->app->send_json(proc2->proc->get_pid(), {{"op", "edit-meta"}});
                });
            }
        }
    });

    button_top_schematic->signal_clicked().connect(
            sigc::mem_fun(*this, &PoolProjectManagerViewProject::open_top_schematic));
    button_board->signal_clicked().connect(sigc::mem_fun(*this, &PoolProjectManagerViewProject::open_board));
    button_part_browser->signal_clicked().connect(
            sigc::mem_fun(*this, &PoolProjectManagerViewProject::handle_button_part_browser));
    button_project_pool->signal_clicked().connect(
            sigc::mem_fun(*this, &PoolProjectManagerViewProject::handle_button_project_pool));
}

void PoolProjectManagerViewProject::open_top_schematic()
{
    auto prj = win->project.get();
    auto top_block = prj->get_top_block();
    std::vector<std::string> args = {top_block.schematic_filename, top_block.block_filename, prj->pictures_directory};
    win->spawn(PoolProjectManagerProcess::Type::IMP_SCHEMATIC, args);
}

void PoolProjectManagerViewProject::open_board()
{
    auto prj = win->project.get();
    auto top_block =
            std::find_if(prj->blocks.begin(), prj->blocks.end(), [](const auto &a) { return a.second.is_top; });
    if (top_block != prj->blocks.end()) {
        std::vector<std::string> args = {prj->board_filename, top_block->second.block_filename, prj->vias_directory,
                                         prj->pictures_directory};
        win->spawn(PoolProjectManagerProcess::Type::IMP_BOARD, args);
    }
}

void PoolProjectManagerViewProject::handle_button_part_browser()
{
    win->part_browser_window->present();
}

void PoolProjectManagerViewProject::handle_button_project_pool()
{
    auto path = Glib::build_filename(win->project->pool_directory, "pool.json");
    win->app->open_pool(path);
}

bool PoolProjectManagerViewProject::update_meta()
{
    auto top_block_filename = win->project->get_top_block().block_filename;
    auto meta = Block::peek_project_meta(top_block_filename);
    std::string title;
    std::string author;
    if (meta.count("project_title"))
        title = meta.at("project_title");
    if (meta.count("author"))
        author = meta.at("author");
    if (title.size())
        win->set_title(title + " - Horizon EDA");
    else
        win->set_title("Project Manager");
    label_project_title->set_text(title);
    label_project_author->set_text(author);
    win->project_title = title;
    return meta.size();
}

void PoolProjectManagerViewProject::update_pool_cache_status(const PoolCacheStatus &status)
{
    std::string txt;
    if (status.n_current == status.n_total) {
        txt = "All current";
    }
    else {
        txt = std::to_string(status.n_out_of_date) + " out of date";
    }
    pool_cache_status_label->set_text(txt);
}

void PoolProjectManagerViewProject::reset_pool_cache_status()
{
    pool_cache_status_label->set_text("");
}

} // namespace horizon
