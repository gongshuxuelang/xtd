/// @file
/// @brief Contains xtd::drawing::drawing2d::smoothing_mode enum class.
/// @copyright Copyright (c) 2022 Gammasoft. All rights reserved.
#pragma once
#include <xtd/ustring.h>

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::drawing namespace provides access to GDI+ basic graphics functionality. More advanced functionality is provided in the xtd::drawing::drawing2d, xtd::drawing::imaging, and xtd::drawing::text namespaces.
  namespace drawing {
    /// @brief The xtd::.drawing::drawing2d namespace provides advanced two-dimensional and vector graphics functionality.
    namespace drawing2d {
      /// @brief Specifies whether smoothing (antialiasing) is applied to lines and curves and the edges of filled areas.
      /// @par Namespace
      /// xtd::drawing::drawing2d
      /// @par Library
      /// xtd.drawing
      /// @ingroup xtd_drawing
      /// @remarks Dxtd::drawing::drawing2d::smoothing_mode::dfault_value, xtd::drawing::drawing2d::smoothing_mode::none, and xtd::drawing::drawing2d::smoothing_mode::xtd::drawing::drawing2d::smoothing_mode::high_speed are equivalent and specify rendering without smoothing applied.
      /// @remarks xtd::drawing::drawing2d::smoothing_mode::anti_alias and xtd::drawing::drawing2d::smoothing_mode::high_quality are equivalent and specify rendering with smoothing applied.
      /// @note When the xtd::drawing::graphics::smoothing_mode property is specified by using the xtd::drawing::drawing2d::smoothing_mode enumeration, it does not affect text. To set the text rendering quality, use the xtd::drawing::graphics::text_rendering_hint property and the xtd::drawing::drawing2d::text_rendering_hint enumeration.
      /// @note When the xtd::drawing::graphics::smoothing_mode property is specified by using the xtd::drawing::drawing2d::smoothing_mode enumeration, it does not affect areas filled by a path gradient brush. Areas filled by using a xtd::drawing::drawing2d::path_gradient_brush object are rendered the same way (aliased) regardless of the setting for the xtd::drawing::graphics::smoothing_mode property.
      enum class smoothing_mode {
        /// @brief Specifies the default mode.
        invalid = -1,
        /// @brief Specifies default mode.
        default_value = 0,
        /// @brief Specifies high speed, low quality rendering.
        high_speed = 1,
        /// @brief Specifies high quality, low speed rendering.
        high_quality = 2,
        /// @brief Specifies no pixel offset.
        none = 3,
        /// @brief Specifies that pixels are offset by -.5 units, both horizontally and vertically, for high speed antialiasing.
        anti_alias = 4,
      };
      
      /// @cond
      inline std::ostream& operator<<(std::ostream& os, smoothing_mode value) {return os << to_string(value, {{smoothing_mode::invalid, "invalid"}, {smoothing_mode::default_value, "default_value"}, {smoothing_mode::high_speed, "high_speed"}, {smoothing_mode::high_quality, "high_quality"}, {smoothing_mode::none, "none"}, {smoothing_mode::anti_alias, "anti_alias"}});}
      inline std::wostream& operator<<(std::wostream& os, smoothing_mode value) {return os << to_string(value, {{smoothing_mode::invalid, L"invalid"}, {smoothing_mode::default_value, L"default_value"}, {smoothing_mode::high_speed, L"high_speed"}, {smoothing_mode::high_quality, L"high_quality"}, {smoothing_mode::none, L"none"}, {smoothing_mode::anti_alias, L"anti_alias"}});}
      /// @endcond
    }
  }
}
