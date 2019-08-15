#pragma once
#include "control.hpp"

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::forms namespace contains classes for creating Windows-based applications that take full advantage of the rich user interface features available in the Microsoft Windows operating system, Apple macOS and Linux like Ubuntu operating system.
  namespace forms {
    class button : public control {
    public:
      button() = default;

      drawing::size default_size() const override {return {75, 25};}

      void create_handle() override; 

      void on_back_color_changed(const event_args& e) override;

      void on_parent_back_color_changed(const event_args& e) override;
    };
  }
}
