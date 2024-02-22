/// @file
/// @brief Contains xtd::drawing::yellow_colors factory.
/// @copyright Copyright (c) 2024 Gammasoft. All rights reserved.
#pragma once
#include "../drawing_export.h"
#include "color.h"
#include <xtd/static>
#include <vector>

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::drawing namespace provides access to GDI+ basic graphics functionality. More advanced functionality is provided in the xtd::drawing::drawing_2d, xtd::drawing::imaging, and xtd::drawing::text namespaces.
  namespace drawing {
    /// @brief Yellow colors for all the hmtl yellow colors. This class cannot be inherited.
    /// @code
    /// class drawing_export_ yellow_colors final static_
    /// @endcode
    /// @par Inheritance
    /// xtd::static_object → xtd::drawing::yellow_colors
    /// @par Namespace
    /// xtd::drawing
    /// @par Library
    /// xtd.drawing
    /// @ingroup xtd_drawing colors
    class drawing_export_ yellow_colors final static_ {
    public:
      /// @name Properties
      
      /// @{
      /// @brief A system-defined color object.
      /// @image html colors_dark_khaki.png
      static xtd::drawing::color dark_khaki() noexcept;
      
      /// @brief A system-defined color object.
      /// @image html colors_gold.png
      static xtd::drawing::color gold() noexcept;
      
      /// @brief A system-defined color object.
      /// @image html colors_khaki.png
      static xtd::drawing::color khaki() noexcept;
      
      /// @brief A system-defined color object.
      /// @image html colors_lemon_chiffon.png
      static xtd::drawing::color lemon_chiffon() noexcept;
      
      /// @brief A system-defined color object.
      /// @image html colors_light_goldenrod_yellow.png
      static xtd::drawing::color light_goldenrod_yellow() noexcept;
      
      /// @brief A system-defined color object.
      /// @image html colors_light_yellow.png
      static xtd::drawing::color light_yellow() noexcept;
      
      /// @brief A system-defined color object.
      /// @image html colors_moccasin.png
      static xtd::drawing::color moccasin() noexcept;
      
      /// @brief A system-defined color object.
      /// @image html colors_pale_goldenrod.png
      static xtd::drawing::color pale_goldenrod() noexcept;
      
      /// @brief A system-defined color object.
      /// @image html colors_papaya_whip.png
      static xtd::drawing::color papaya_whip() noexcept;
      
      /// @brief A system-defined color object.
      /// @image html colors_peach_puff.png
      static xtd::drawing::color peach_puff() noexcept;
      
      /// @brief A system-defined color object.
      /// @image html colors_yellow.png
      static xtd::drawing::color yellow() noexcept;
      /// @}
      
      /// @name Methods
      
      /// @{
      /// @brief Gets an array of colors.
      static const std::vector<xtd::drawing::color>& get_colors() noexcept;
      
      /// @brief Gets an array of color names.
      static const std::vector<xtd::ustring>& get_color_names() noexcept;
      /// @}
    };
  }
}
