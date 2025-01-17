/// @file
/// @brief Contains xtd::collections::any_pair typedef.
/// @copyright Copyright (c) 2024 Gammasoft. All rights reserved.
#pragma once
#include "../any.h"
#include <utility>

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  namespace collections {
    /// @brief Implements a std::pair with the key and the value strongly typed to be std::any.
    /// ```cpp
    /// using any_pair = std::pair<std::any, std::any>
    /// ```
    /// @par Header
    /// ```cpp
    /// #include <xtd/collections/any_pair>
    /// ```
    /// @par Namespace
    /// xtd::collections
    /// @par Library
    /// xtd.core
    /// @ingroup xtd_core collections
    using any_pair = std::pair<std::any, std::any>;
  }
}
