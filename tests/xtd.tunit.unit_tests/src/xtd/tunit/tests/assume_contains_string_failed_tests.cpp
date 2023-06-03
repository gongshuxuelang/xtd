#include "../../../assert_unit_tests/assert_unit_tests.h"
#include <xtd/xtd.tunit>
#include <string>

namespace xtd::tunit::tests {
  class test_class_(assume_contains_string_failed_tests) {
  public:
    void test_method_(test_case_failed) {
      std::string s = "string";
      xtd::tunit::assume::contains('a', s);
    }
  };
}

void test_(assume_contains_string_failed_tests, test_output) {
  auto [output, result] = run_test_("assume_contains_string_failed_tests.*");
  assert_value_("Start 1 test from 1 test case\n"
    "  ABORTED assume_contains_string_failed_tests.test_case_failed\n"
    "    Test aborted\n"
    "End 1 test from 1 test case ran.\n", output);
}

void test_(assume_contains_string_failed_tests, test_result) {
  auto [output, result] = run_test_("assume_contains_string_failed_tests.*");
  assert_value_(0, result);
}