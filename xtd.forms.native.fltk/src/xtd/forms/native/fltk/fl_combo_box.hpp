#pragma once
#include <stdexcept>
#include <xtd/forms/create_params.hpp>
#include <xtd/forms/native/combo_box_styles.hpp>
#include "control_handler.hpp"
#include <FL/Fl_Input_Choice.H>
#include <FL/Fl_Choice.H>

namespace xtd {
  namespace forms {
    namespace native {
      class fl_combo_box : public control_handler {
      public:
        fl_combo_box(const xtd::forms::create_params& create_params) {
          if (!create_params.parent()) throw std::invalid_argument("control must have a parent");
          if ((create_params.style() & CBS_SIMPLE) == CBS_SIMPLE)
            this->control_handler::create<Fl_Choice>(create_params.x(), create_params.y(), create_params.width(), create_params.height());
          else
            this->control_handler::create<Fl_Input_Choice>(create_params.x(), create_params.y(), create_params.width(), create_params.height());
          this->control()->copy_label(create_params.caption().c_str());
          reinterpret_cast<Fl_Group*>(reinterpret_cast<control_handler*>(create_params.parent())->control())->add(this->control());
        }
      };
    }
  }
}
