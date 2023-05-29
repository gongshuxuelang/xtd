#include "assert_unit_tests.h"
#include <xtd/xtd.tunit>

namespace xtd::tunit::tests {
  class test_class_(valid_are_equal_long_double_with_tolerence_failed_tests) {
  public:
    void test_method_(test_case_failed) {
      long double ld = 0.599l;
      xtd::tunit::valid::are_equal(0.6l, ld, 0.001l);
    }
  };
}

void test_(valid_are_equal_long_double_with_tolerence_failed_tests, test_output) {
  xtd::tunit::settings::default_settings().exit_status(0);
  xtd::tunit::settings::default_settings().filter_tests("valid_are_equal_long_double_with_tolerence_failed_tests.*");
  std::stringstream ss;
  xtd::tunit::unit_test(std::make_unique<assert_unit_tests::unit_tests_event_listener>(ss)).run();
  assert_value_("Start 1 test from 1 test case\n"
    "  FAILED  valid_are_equal_long_double_with_tolerence_failed_tests.test_case_failed\n"
    "    Expected: 0.6\n"
    "    But was:  0.599\n"
    "End 1 test from 1 test case ran.\n", ss.str());
}

void test_(valid_are_equal_long_double_with_tolerence_failed_tests, test_result) {
  xtd::tunit::settings::default_settings().exit_status(0);
  xtd::tunit::settings::default_settings().filter_tests("valid_are_equal_long_double_with_tolerence_failed_tests.*");
  std::stringstream ss;
  assert_value_(1, xtd::tunit::unit_test(std::make_unique<assert_unit_tests::unit_tests_event_listener>(ss)).run());
}