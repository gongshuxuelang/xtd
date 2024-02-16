#include <xtd/forms/combo_box>
#include <xtd/forms/form>
#include <xtd/diagnostics/debugger>
#include <xtd/tunit/assert>
#include <xtd/tunit/collection_assert>
#include <xtd/tunit/test_class_attribute>
#include <xtd/tunit/test_method_attribute>

using namespace xtd;
using namespace xtd::drawing;
using namespace xtd::forms;
using namespace xtd::tunit;

namespace xtd::forms::tests {
  class test_class_(combo_box_tests) {
    class combo_box_for_test : public combo_box {
    public:
      combo_box_for_test() = default;
      
      using combo_box::default_back_color;
      using combo_box::default_cursor;
      using combo_box::default_font;
      using combo_box::default_fore_color;
      using combo_box::default_size;
    };
    
    void test_method_(constructor) {
      combo_box_for_test combo_box;
      assert::are_equal(anchor_styles::left | anchor_styles::top, combo_box.anchor(), csf_);
      assert::are_equal(drawing::point::empty, combo_box.auto_scroll_point(), csf_);
      assert::is_false(combo_box.auto_size(), csf_);
      assert::are_equal(style_sheets::style_sheet::current_style_sheet().system_colors().window(), combo_box.back_color(), csf_);
      assert::are_equal(drawing::image::empty, combo_box.background_image(), csf_);
      assert::are_equal(image_layout::tile, combo_box.background_image_layout(), csf_);
      assert::are_equal(combo_box.default_size().height(), combo_box.bottom(), csf_);
      assert::are_equal(drawing::rectangle({0, 0}, combo_box.default_size()), combo_box.bounds(), csf_);
      assert::is_false(combo_box.can_focus(), csf_);
      assert::is_true(combo_box.can_raise_events(), csf_);
      assert::is_true(combo_box.can_select(), csf_);
      assert::are_equal(drawing::rectangle({0, 0}, combo_box.default_size()), combo_box.client_rectangle(), csf_);
      assert::are_equal(combo_box.default_size(), combo_box.client_size(), csf_);
      assert::are_equal("Gammasoft", combo_box.company_name(), csf_);
      assert::is_null(combo_box.context_menu(), csf_);
      assert::are_equal(forms::control_appearance::system, combo_box.control_appearance(), csf_);
      assert::is_empty(combo_box.controls(), csf_);
      assert::is_false(combo_box.created(), csf_);
      assert::are_equal(forms::cursors::default_cursor(), combo_box.cursor(), csf_);
      assert::are_equal(style_sheets::style_sheet::current_style_sheet().system_colors().window(), combo_box.default_back_color(), csf_);
      assert::are_equal(forms::cursors::default_cursor(), combo_box.default_cursor(), csf_);
      assert::are_equal(drawing::system_fonts::default_font(), combo_box.default_font(), csf_);
      assert::are_equal(style_sheets::style_sheet::current_style_sheet().system_colors().window_text(), combo_box.default_fore_color(), csf_);
      assert::are_equal(combo_box.default_size(), combo_box.default_size(), csf_);
      assert::are_equal(drawing::rectangle({0, 0}, combo_box.default_size()), combo_box.display_rectangle(), csf_);
      assert::are_equal(forms::dock_style::none, combo_box.dock(), csf_);
      assert::is_false(combo_box.double_buffered(), csf_);
      assert::is_true(combo_box.enabled(), csf_);
      assert::is_false(combo_box.focused(), csf_);
      assert::are_equal(drawing::system_fonts::default_font(), combo_box.font(), csf_);
      assert::are_equal(style_sheets::style_sheet::current_style_sheet().system_colors().window_text(), combo_box.fore_color(), csf_);
      assert::is_zero(combo_box.handle(), csf_);
      assert::are_equal(combo_box.default_size().height(), combo_box.height(), csf_);
      assert::is_false(combo_box.invoke_required(), csf_);
      assert::is_false(combo_box.is_handle_created(), csf_);
      assert::is_zero(combo_box.left(), csf_);
      assert::are_equal(drawing::point::empty, combo_box.location(), csf_);
      assert::are_equal(forms::padding(3), combo_box.margin(), csf_);
      assert::are_equal(drawing::size::empty, combo_box.maximum_client_size(), csf_);
      assert::are_equal(drawing::size::empty, combo_box.maximum_size(), csf_);
      assert::are_equal(drawing::size::empty, combo_box.minimum_client_size(), csf_);
      assert::are_equal(drawing::size::empty, combo_box.minimum_size(), csf_);
      assert::is_zero(combo_box.native_handle(), csf_);
      assert::is_empty(combo_box.name(), csf_);
      assert::are_equal(forms::padding(0), combo_box.padding(), csf_);
      assert::is_null(combo_box.parent(), csf_);
      assert::are_equal("xtd", combo_box.product_name(), csf_);
      assert::is_not_zero(combo_box.region().handle(), csf_);
      assert::are_equal(combo_box.default_size().width(), combo_box.right(), csf_);
      assert::are_equal(combo_box.default_size(), combo_box.size(), csf_);
      assert::is_empty(combo_box.style_sheet().theme().name(), csf_);
      assert::is_true(combo_box.tab_stop(), csf_);
      assert::is_false(combo_box.tag().has_value(), csf_);
      assert::is_empty(combo_box.text(), csf_);
      assert::is_zero(combo_box.toolkit_handle(), csf_);
      assert::is_zero(combo_box.top(), csf_);
      assert::is_null(combo_box.top_level_control(), csf_);
      assert::is_true(combo_box.visible(), csf_);
      assert::are_equal(combo_box.default_size().width(), combo_box.width(), csf_);
      assert::are_equal(diagnostics::debugger::is_attached(), forms::control::check_for_illegal_cross_thread_calls(), csf_);
      assert::are_equal(keys::none, forms::control::modifier_keys(), csf_);
      assert::are_equal(forms::mouse_buttons::none, forms::control::mouse_buttons(), csf_);
      // The following test may fail: The user can place the mouse in the upper left position of the screen {0, 0}...
      // assert::are_not_equal(drawing::point::empty, forms::control::mouse_position(), csf_);
      
      assert::is_false(combo_box.dropped_down(), csf_);
      assert::are_equal(combo_box_style::drop_down, combo_box.drop_down_style(), csf_);
      collection_assert::is_empty(combo_box.items(), csf_);
      assert::are_equal(combo_box::object_collection::npos, combo_box.selected_index(), csf_);
      assert::are_equal(combo_box::item::empty, combo_box.selected_item(), csf_);
      assert::is_false(combo_box.sorted(), csf_);
      assert::is_empty(combo_box.text(), csf_);
    }
  };
}
