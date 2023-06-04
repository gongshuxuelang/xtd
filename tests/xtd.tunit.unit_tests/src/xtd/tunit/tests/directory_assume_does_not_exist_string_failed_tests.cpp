#include "../../../assert_unit_tests/assert_unit_tests.h"
#include <xtd/xtd.tunit>

namespace xtd::tunit::tests {
  class test_class_(directory_assume_does_not_exist_string_failed_tests) {
  public:
    void test_method_(test_case_failed) {
      auto d = environment::get_folder_path(environment::special_folder::common_application_data);
      xtd::tunit::directory_assume::does_not_exist(d);
    }
  };
}

void test_(directory_assume_does_not_exist_string_failed_tests, test_output) {
  auto [output, result] = run_test_("directory_assume_does_not_exist_string_failed_tests.*");
  assert_value_("Start 1 test from 1 test case\n"
    "  ABORTED directory_assume_does_not_exist_string_failed_tests.test_case_failed\n"
    "    Test aborted\n"
    "End 1 test from 1 test case ran.\n", output);
}

void test_(directory_assume_does_not_exist_string_failed_tests, test_result) {
  auto [output, result] = run_test_("directory_assume_does_not_exist_string_failed_tests.*");
  assert_value_(0, result);
}