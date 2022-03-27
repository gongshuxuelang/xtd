#include "../../../include/xtd/forms/image_renderer.h"
#include "../../../include/xtd/forms/text_renderer.h"
#include "../../../include/xtd/forms/toggle_button_renderer.h"
#include "../../../include/xtd/forms/style_sheets/button.h"
#include "../../../include/xtd/forms/style_sheets/pseudo_state.h"
#include "../../../include/xtd/forms/style_sheets/style_sheet.h"

using namespace std;
using namespace xtd;
using namespace xtd::drawing;
using namespace xtd::forms;
using namespace xtd::forms::style_sheets;
using namespace xtd::forms::visual_styles;

void toggle_button_renderer::draw_toggle_button(const style_sheets::style_sheet& style_sheet, graphics& graphics, const rectangle& bounds, toggle_button_state state, const optional<color>& back_color, const xtd::ustring& text, const std::optional<xtd::forms::content_alignment>& text_align, const std::optional<xtd::drawing::color>& fore_color, const std::optional<xtd::drawing::font>& font, const xtd::drawing::image& image, const std::optional<xtd::forms::content_alignment>& image_align) {
  style_sheets::toggle_button current_style_sheet;
  switch (state) {
    case toggle_button_state::unchecked_normal: current_style_sheet = style_sheet.toggle_button(style_sheets::pseudo_state::standard); break;
    case toggle_button_state::unchecked_hot: current_style_sheet = style_sheet.toggle_button(style_sheets::pseudo_state::standard | pseudo_state::hover); break;
    case toggle_button_state::unchecked_pressed: current_style_sheet = style_sheet.toggle_button(style_sheets::pseudo_state::standard | pseudo_state::pressed); break;
    case toggle_button_state::unchecked_disabled: current_style_sheet = style_sheet.toggle_button(style_sheets::pseudo_state::standard | pseudo_state::disabled); break;
    case toggle_button_state::checked_normal: current_style_sheet = style_sheet.toggle_button(style_sheets::pseudo_state::checked); break;
    case toggle_button_state::checked_hot: current_style_sheet = style_sheet.toggle_button(style_sheets::pseudo_state::checked | pseudo_state::hover); break;
    case toggle_button_state::checked_pressed: current_style_sheet = style_sheet.toggle_button(style_sheets::pseudo_state::checked | pseudo_state::pressed); break;
    case toggle_button_state::checked_disabled: current_style_sheet = style_sheet.toggle_button(style_sheets::pseudo_state::checked | pseudo_state::disabled); break;
    case toggle_button_state::mixed_normal: current_style_sheet = style_sheet.toggle_button(style_sheets::pseudo_state::mixed); break;
    case toggle_button_state::mixed_hot: current_style_sheet = style_sheet.toggle_button(style_sheets::pseudo_state::mixed | pseudo_state::hover); break;
    case toggle_button_state::mixed_pressed: current_style_sheet = style_sheet.toggle_button(style_sheets::pseudo_state::mixed | pseudo_state::pressed); break;
    case toggle_button_state::mixed_disabled: current_style_sheet = style_sheet.toggle_button(style_sheets::pseudo_state::mixed | pseudo_state::disabled); break;
  }
  
  if (back_color.has_value() && state == toggle_button_state::unchecked_normal) current_style_sheet.background_color(back_color.value());
  if (text_align.has_value()) current_style_sheet.text_alignment(text_align.value());
  if (fore_color.has_value() && state != toggle_button_state::unchecked_disabled && state != toggle_button_state::checked_disabled && state != toggle_button_state::mixed_disabled) current_style_sheet.color(fore_color.value());
  if (font.has_value()) current_style_sheet.font(font.value());
  if (image_align.has_value()) current_style_sheet.image_alignment(image_align.value());
  
  box_renderer::draw_box(graphics, bounds, current_style_sheet);
  auto content_rectangle = current_style_sheet.get_content_rectangle(bounds);
  image_renderer::draw_image(graphics, content_rectangle, image, state != toggle_button_state::unchecked_disabled && state != toggle_button_state::checked_disabled && state != toggle_button_state::mixed_disabled, current_style_sheet.get_solid_background_color(), current_style_sheet);
  text_renderer::draw_text(graphics, content_rectangle, text, current_style_sheet);
}
