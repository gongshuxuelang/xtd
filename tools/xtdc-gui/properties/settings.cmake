setting(menu_visible bool USER "true")
setting(auto_close bool USER "true")
setting(create_propject_folder xtd::ustring USER "xtd::environment::get_folder_path(xtd::environment::special_folder::home)")
setting(open_propject_folder xtd::ustring USER "xtd::environment::get_folder_path(xtd::environment::special_folder::home)")
setting(open_recent_propjects xtd::ustring USER "")
setting(create_recent_propjects xtd::ustring USER "")
setting(language_index size_t USER "1")
setting(platform_index size_t USER "static_cast<size_t>(xtd::environment::os_version().is_windows_platform() ? 1 : xtd::environment::os_version().is_unix_platform() ? 2 : 3)")
setting(type_index size_t USER "0")
