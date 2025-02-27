#pragma once
#include "core/core_board.hpp"
#include "imp_layer.hpp"
#include "search/searcher_board.hpp"

namespace horizon {
class ImpBoard : public ImpLayer {
public:
    ImpBoard(const std::string &board_filename, const std::string &block_filename, const std::string &via_dir,
             const std::string &pictures_dir, const PoolParams &params);

    const std::map<int, Layer> &get_layers();
    void update_highlights() override;

    std::map<ObjectType, SelectionFilterInfo> get_selection_filter_info() const override;

    ~ImpBoard();

protected:
    void construct() override;
    bool handle_broadcast(const json &j) override;
    void handle_maybe_drag() override;
    void update_action_sensitivity() override;
    void apply_preferences() override;

    ActionCatalogItem::Availability get_editor_type_for_action() const override
    {
        return ActionCatalogItem::AVAILABLE_IN_BOARD;
    };

    std::string get_hud_text(std::set<SelectableRef> &sel) override;
    ActionToolID get_doubleclick_action(ObjectType type, const UUID &uu) override;

    void get_save_meta(json &j) override;
    std::vector<std::string> get_view_hints() override;

    Searcher *get_searcher_ptr() override
    {
        return &searcher;
    }

    ToolID get_tool_for_drag_move(bool ctrl, const std::set<SelectableRef> &sel) const override;

    void update_monitor() override;

private:
    void canvas_update() override;
    void handle_selection_cross_probe() override;

    CoreBoard core_board;
    const std::string project_dir;
    SearcherBoard searcher;

    class FabOutputWindow *fab_output_window = nullptr;
    class View3DWindow *view_3d_window = nullptr;
    class StepExportWindow *step_export_window = nullptr;
    class TuningWindow *tuning_window = nullptr;
    class PDFExportWindow *pdf_export_window = nullptr;
    class BoardDisplayOptionsBox *board_display_options_box = nullptr;
    class PnPExportWindow *pnp_export_window = nullptr;
    class AirwireFilterWindow *airwire_filter_window = nullptr;
    class PartsWindow *parts_window = nullptr;
    bool cross_probing_enabled = false;

    Coordf cursor_pos_drag_begin;
    Target target_drag_begin;

    void handle_drag();
    void handle_measure_tracks(const ActionConnection &a);

    class CanvasAnnotation *text_owner_annotation = nullptr;
    std::map<UUID, UUID> text_owners;
    void update_text_owners();
    void update_text_owner_annotation();

    void handle_select_more(const ActionConnection &conn);

    class UnplacedBox *unplaced_box = nullptr;
    void update_unplaced();

    void update_airwires();

    int get_schematic_pid();

    class CanvasAnnotation *airwire_annotation = nullptr;
    void update_airwire_annotation();
    void update_net_colors();
    void apply_net_colors();
    std::map<UUID, uint8_t> net_color_map;

    Gtk::Popover *reload_netlist_popover = nullptr;
    sigc::connection reload_netlist_delay_conn;

    UUID net_from_selectable(const SelectableRef &sr);
};
} // namespace horizon
