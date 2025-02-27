#pragma once
#include <gtkmm.h>
#include "preferences/preferences.hpp"
#include "nlohmann/json.hpp"

namespace horizon {
using json = nlohmann::json;
class PartinfoPreferencesEditor : public Gtk::Box {
public:
    PartinfoPreferencesEditor(BaseObjectType *cobject, const Glib::RefPtr<Gtk::Builder> &x, class Preferences &prefs);
    static PartinfoPreferencesEditor *create(Preferences &prefs);

private:
    Preferences &preferences;
    PartInfoPreferences &partinfo_preferences;
    Gtk::Switch *partinfo_enable_switch = nullptr;
    Gtk::Entry *partinfo_base_url_entry = nullptr;
    Gtk::ComboBoxText *partinfo_preferred_distributor_combo = nullptr;
    Gtk::CheckButton *partinfo_ignore_moq_1_cb = nullptr;
    Gtk::SpinButton *partinfo_max_price_breaks_sp = nullptr;
    Gtk::SpinButton *partinfo_cache_days_sp = nullptr;
    void update_warnings();
};


} // namespace horizon
