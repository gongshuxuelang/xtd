/// @file
/// @brief Contains xtd::forms::control_layout_style class.
/// @copyright Copyright (c) 2021 Gammasoft. All rights reserved.
#pragma once
#include <xtd/strings.h>
#include "size_type.h"

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::forms namespace contains classes for creating Windows-based applications that take full advantage of the rich user interface features available in the Microsoft Windows operating system, Apple macOS and Linux like Ubuntu operating system.
  namespace forms {
    /// @brief Implements the basic functionality that represents the appearance and behavior of a control layout.
    /// @par Library
    /// xtd.forms
    /// @ingroup xtd_forms
    class control_layout_style {
    protected:
      /// @brief Initialises a new instance of control layout style class.
      control_layout_style() = default;
      /// @brief Initialises a new instance of control layout style class with specified expanded.
      /// @param expanded true if control expanded; otherwise false.
      explicit control_layout_style(bool expanded) : expanded_(expanded) {}
      /// @brief Initialises a new instance of control layout style class with specified size type.
      /// @param size_type One of the xtd::forms::size_type values that specifies how layout container of user interface (UI) elements should be sized relative to their container. The default is xtd::forms::size_type::auto_size.
      explicit control_layout_style(xtd::forms::size_type size_type) : size_type_(size_type) {}
      /// @brief Initialises a new instance of control layout style class with specified expanded and size type.
      /// @param expanded true if control expanded; otherwise false.
      /// @param size_type One of the xtd::forms::size_type values that specifies how layout container of user interface (UI) elements should be sized relative to their container. The default is xtd::forms::size_type::auto_size.
      explicit control_layout_style(bool expanded, xtd::forms::size_type size_type) : expanded_(expanded), size_type_(size_type) {}

    public:
      /// @brief Gets a flag indicating how a control should be sized relative to its containing layout container.
      /// @return One of the xtd::forms::size_type values that specifies how layout container of user interface (UI) elements should be sized relative to their container. The default is xtd::forms::size_type::auto_size.
      xtd::forms::size_type size_type() const {return size_type_;}
      /// @brief Sets a flag indicating how a control should be sized relative to its containing layout container.
      /// @param size_type One of the xtd::forms::size_type values that specifies how layout container of user interface (UI) elements should be sized relative to their container. The default is xtd::forms::size_type::auto_size.
      control_layout_style& size_type(xtd::forms::size_type size_type) {
        size_type_ = size_type;
        return *this;
      }

      bool expanded() const {return expanded_;}
      control_layout_style& expanded(bool expanded) {
        expanded_ = expanded;
        return *this;
      }

      /// @brief Returns a string that represent xtd::forms::control_layout_style.
      /// @return A string containing that represent xtd::forms::control_layout_style.
      virtual std::string to_string() const {return strings::format("control_layout_style=[expanded={}, size_type={}]", expanded_, size_type_);}
      
      /// @cond
      bool operator==(const control_layout_style& value) const {return size_type_ == value.size_type_ && expanded_ == value.expanded_;}
      bool operator!=(const control_layout_style& value) const {return !operator==(value);}
      friend std::ostream& operator<<(std::ostream& os, const xtd::forms::control_layout_style& control_layout_style) noexcept {
        return os << control_layout_style.to_string();
      }
      /// @endcond

    private:
      bool expanded_ = true;
      xtd::forms::size_type size_type_ = xtd::forms::size_type::auto_size;
    };
  }
}
