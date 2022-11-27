#define __XTD_FORMS_NATIVE_LIBRARY__
#include <xtd/forms/native/file_dialog.h>
#undef __XTD_FORMS_NATIVE_LIBRARY__
#include "../../../include/xtd/forms/application.h"
#include "../../../include/xtd/forms/open_file_dialog.h"
#include "xtd_forms_common_dialog_closed_caller.h"

using namespace xtd;
using namespace xtd::forms;

bool open_file_dialog::run_file_dialog(intptr_t owner) {
  return native::file_dialog::run_open_dialog(owner, data_->default_ext, data_->file_name, data_->file_names, data_->filter, data_->filter_index, data_->initial_directory, data_->options, data_->support_multi_dotted_extensions, data_->title);
}

void open_file_dialog::run_file_sheet(intptr_t owner) {
  if (!owner) run_file_dialog(owner);
  else native::file_dialog::run_open_sheet({*new __xtd_forms_common_dialog_closed_caller__(this), &__xtd_forms_common_dialog_closed_caller__::on_common_dialog_closed}, owner, data_->default_ext, data_->file_name, data_->file_names, data_->filter, data_->filter_index, data_->initial_directory, data_->options, data_->support_multi_dotted_extensions, data_->title);
}
