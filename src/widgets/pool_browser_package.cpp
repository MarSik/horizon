#include "pool_browser_package.hpp"
#include "pool/ipool.hpp"
#include "util/sqlite.hpp"
#include "tag_entry.hpp"
#include <set>

namespace horizon {
PoolBrowserPackage::PoolBrowserPackage(IPool &p, bool pads_filter, const std::string &instance)
    : PoolBrowser(p, TreeViewStateStore::get_prefix(instance, "pool_browser_package"))
{
    construct();
    name_entry = create_search_entry("Name");
    manufacturer_entry = create_search_entry("Manufacturer");
    tag_entry = create_tag_entry("Tags", create_pool_selector());
    if (pads_filter) {
        pads_cb = Gtk::manage(new Gtk::CheckButton);
        pads_cb->set_active(true);
        pads_sp = Gtk::manage(new Gtk::SpinButton);
        pads_sp->set_range(1, 2000);
        pads_sp->set_increments(1, 1);
        pads_cb->show();
        pads_sp->show();
        auto box = Gtk::manage(new Gtk::Box(Gtk::ORIENTATION_HORIZONTAL, 5));
        box->pack_start(*pads_cb, false, false, 0);
        box->pack_start(*pads_sp, false, false, 0);
        add_search_widget("Pads", *box);
        pads_cb->signal_toggled().connect([this] {
            pads_sp->set_sensitive(pads_cb->get_active());
            search();
        });
        pads_sp->signal_value_changed().connect(sigc::mem_fun(*this, &PoolBrowserPackage::search));
    }
    install_pool_item_source_tooltip();
}

void PoolBrowserPackage::set_pads_filter(unsigned int n)
{
    if (pads_sp)
        pads_sp->set_value(n);
}

Glib::RefPtr<Gtk::ListStore> PoolBrowserPackage::create_list_store()
{
    return Gtk::ListStore::create(list_columns);
}

void PoolBrowserPackage::create_columns()
{
    {
        auto col = append_column_with_item_source_cr("Package", list_columns.name, Pango::ELLIPSIZE_END);
        col->set_resizable(true);
        col->set_min_width(150);
        install_column_tooltip(*col, list_columns.name);
    }
    {
        auto col = append_column("Manufacturer", list_columns.manufacturer, Pango::ELLIPSIZE_END);
        col->set_resizable(true);
        col->set_min_width(30);
    }
    treeview->append_column("Pads", list_columns.n_pads);
    {
        auto col = append_column("Tags", list_columns.tags, Pango::ELLIPSIZE_END);
        col->set_resizable(true);
        col->set_min_width(100);
        install_column_tooltip(*col, list_columns.tags);
    }
    path_column = append_column("Path", list_columns.path, Pango::ELLIPSIZE_START);
    install_column_tooltip(*path_column, list_columns.path);
}

void PoolBrowserPackage::add_sort_controller_columns()
{
    sort_controller->add_column(0, "packages.name");
    sort_controller->add_column(1, "packages.manufacturer");
    sort_controller->add_column(2, "packages.n_pads");
}

void PoolBrowserPackage::search()
{
    prepare_search();

    Gtk::TreeModel::Row row;
    const std::string name_search = name_entry->get_text();
    const std::string manufacturer_search = manufacturer_entry->get_text();

    const auto tags = tag_entry->get_tags();
    std::string query =
            "SELECT packages.uuid, packages.name, packages.manufacturer, "
            "packages.n_pads, tags_view.tags, packages.filename, packages.pool_uuid, packages.last_pool_uuid "
            "FROM packages "
            "LEFT JOIN tags_view ON tags_view.uuid = packages.uuid AND tags_view.type = 'package' ";
    query += get_tags_query(tags);
    query += "WHERE packages.name LIKE $name AND packages.manufacturer LIKE $manufacturer ";
    if (pads_cb && pads_cb->get_active()) {
        query += "AND packages.n_pads = $npads ";
    }
    query += get_pool_selector_query();
    query += sort_controller->get_order_by();

    SQLite::Query q(pool.get_db(), query);
    q.bind("$name", "%" + name_search + "%");
    q.bind("$manufacturer", "%" + manufacturer_search + "%");
    bind_tags_query(q, tags);
    if (pads_cb && pads_cb->get_active()) {
        q.bind("$npads", pads_sp->get_value_as_int());
    }
    bind_pool_selector_query(q);

    if (show_none) {
        row = *(store->append());
        row[list_columns.uuid] = UUID();
        row[list_columns.name] = "none";
        row[list_columns.manufacturer] = "none";
    }
    try {
        while (q.step()) {
            row = *(store->append());
            row[list_columns.uuid] = q.get<std::string>(0);
            row[list_columns.name] = q.get<std::string>(1);
            row[list_columns.manufacturer] = q.get<std::string>(2);
            row[list_columns.n_pads] = q.get<int>(3);
            row[list_columns.tags] = q.get<std::string>(4);
            row[list_columns.path] = q.get<std::string>(5);
            row[list_columns.source] = pool_item_source_from_db(q, 6, 7);
        }
        set_busy(false);
    }
    catch (SQLite::Error &e) {
        if (e.rc == SQLITE_BUSY) {
            set_busy(true);
        }
        else {
            throw;
        }
    }

    finish_search();
}

UUID PoolBrowserPackage::uuid_from_row(const Gtk::TreeModel::Row &row)
{
    return row[list_columns.uuid];
}
PoolBrowser::PoolItemSource PoolBrowserPackage::pool_item_source_from_row(const Gtk::TreeModel::Row &row)
{
    return row[list_columns.source];
}
} // namespace horizon
