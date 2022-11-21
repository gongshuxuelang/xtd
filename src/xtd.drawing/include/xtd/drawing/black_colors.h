/// @file
/// @brief Contains xtd::drawing::gray_and_black_colors factory.
/// @copyright Copyright (c) 2022 Gammasoft. All rights reserved.
#pragma once
#include "gray_colors.h"

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::drawing namespace provides access to GDI+ basic graphics functionality. More advanced functionality is provided in the xtd::drawing::drawing2d, xtd::drawing::imaging, and xtd::drawing::text namespaces.
  namespace drawing {
    /// @brief Gray and black colors for all the hmtl gray and black colors.
    /// @par Namespace
    /// xtd::drawing
    /// @par Library
    /// xtd.drawing
    /// @ingroup xtd_drawing drawing
    using black_colors = xtd::drawing::gray_colors;
  }
}
