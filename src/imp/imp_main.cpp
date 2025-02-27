#include "imp.hpp"
#include "imp_board.hpp"
#include "imp_package.hpp"
#include "imp_padstack.hpp"
#include "imp_schematic.hpp"
#include "imp_symbol.hpp"
#include "imp_frame.hpp"
#include "imp_decal.hpp"
#include "pool/part.hpp"
#include "pool/pool.hpp"
#include "pool/symbol.hpp"
#include "pool/unit.hpp"
#include "util/util.hpp"
#include "util/uuid.hpp"
#include "pool/pool_manager.hpp"
#include "util/exception_util.hpp"
#include "util/automatic_prefs.hpp"
#include <curl/curl.h>
#include <fstream>
#include <iostream>
#include <memory>
#ifdef G_OS_WIN32
#include <windows.h>
#endif

using horizon::Canvas;
using horizon::LutEnumStr;
using horizon::UUID;
using std::cout;

using json = nlohmann::json;

int main(int argc, char *argv[])
{
#ifdef G_OS_WIN32
    SetErrorMode(SEM_FAILCRITICALERRORS | SEM_NOGPFAULTERRORBOX | SEM_NOOPENFILEERRORBOX);
#endif

    gtk_disable_setlocale();
    Gio::init();
    horizon::PoolManager::init();
    horizon::AutomaticPreferences::get();

    Glib::OptionContext options;
    options.set_summary("horizon interactive manipulator");
    options.set_help_enabled();

    Glib::OptionGroup group("imp", "imp");

    bool mode_symbol = false;
    Glib::OptionEntry entry;
    entry.set_long_name("symbol");
    entry.set_short_name('y');
    entry.set_description("Symbol mode");
    group.add_entry(entry, mode_symbol);

    bool mode_sch = false;
    Glib::OptionEntry entry2;
    entry2.set_long_name("schematic");
    entry2.set_short_name('c');
    entry2.set_description("Schematic mode");
    group.add_entry(entry2, mode_sch);

    bool mode_padstack = false;
    Glib::OptionEntry entry3;
    entry3.set_long_name("padstack");
    entry3.set_short_name('a');
    entry3.set_description("Padstack mode");
    group.add_entry(entry3, mode_padstack);

    bool mode_package = false;
    Glib::OptionEntry entry4;
    entry4.set_long_name("package");
    entry4.set_short_name('k');
    entry4.set_description("Package mode");
    group.add_entry(entry4, mode_package);

    bool mode_board = false;
    Glib::OptionEntry entry5;
    entry5.set_long_name("board");
    entry5.set_short_name('b');
    entry5.set_description("Board mode");
    group.add_entry(entry5, mode_board);

    bool mode_frame = false;
    Glib::OptionEntry entry7;
    entry7.set_long_name("frame");
    entry7.set_short_name('f');
    entry7.set_description("Frame mode");
    group.add_entry(entry7, mode_frame);

    bool mode_decal = false;
    Glib::OptionEntry entry8;
    entry8.set_long_name("decal");
    entry8.set_short_name('d');
    entry8.set_description("Decal mode");
    group.add_entry(entry8, mode_decal);

    bool read_only = false;
    Glib::OptionEntry entry6;
    entry6.set_long_name("read-only");
    entry6.set_short_name('r');
    entry6.set_description("Read only");
    group.add_entry(entry6, read_only);

    std::vector<std::string> filenames;
    Glib::OptionEntry entry_f;
    entry_f.set_long_name(G_OPTION_REMAINING);
    entry_f.set_short_name(' ');
    entry_f.set_description("Filename");
    group.add_entry_filename(entry_f, filenames);

    options.set_main_group(group);
    options.parse(argc, argv);

    auto pool_base_path = Glib::getenv("HORIZON_POOL");
    horizon::setup_locale();

    horizon::create_config_dir();

    std::unique_ptr<horizon::ImpBase> imp = nullptr;
    if (mode_sch) {
        imp.reset(new horizon::ImpSchematic(filenames.at(0), filenames.at(1), filenames.at(2), {pool_base_path}));
    }
    else if (mode_symbol) {
        imp.reset(new horizon::ImpSymbol(filenames.at(0), pool_base_path));
    }
    else if (mode_padstack) {
        imp.reset(new horizon::ImpPadstack(filenames.at(0), pool_base_path));
    }
    else if (mode_package) {
        imp.reset(new horizon::ImpPackage(filenames.at(0), pool_base_path));
    }
    else if (mode_board) {
        imp.reset(new horizon::ImpBoard(filenames.at(0), filenames.at(1), filenames.at(2), filenames.at(3),
                                        {pool_base_path}));
    }
    else if (mode_frame) {
        imp.reset(new horizon::ImpFrame(filenames.at(0), pool_base_path));
    }
    else if (mode_decal) {
        imp.reset(new horizon::ImpDecal(filenames.at(0), pool_base_path));
    }
    else {
        std::cout << "wrong invocation" << std::endl;
        return 1;
    }
    imp->set_read_only(read_only);

    horizon::install_signal_exception_handler();
    imp->run(argc, argv);

    return 0;
}
