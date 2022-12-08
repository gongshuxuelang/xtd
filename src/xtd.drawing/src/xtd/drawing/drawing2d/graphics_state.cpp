#include <stdexcept>
#include "../../../../include/xtd/drawing/drawing2d/graphics_state.h"

using namespace xtd::drawing::drawing2d;

bool graphics_state::equals(const graphics_state& value) const noexcept {
  return handle_ == value.handle_;
}
