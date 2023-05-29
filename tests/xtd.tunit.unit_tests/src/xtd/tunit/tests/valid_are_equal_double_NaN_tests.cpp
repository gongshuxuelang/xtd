#include "assert_unit_tests.h"
#include <xtd/xtd.tunit>

namespace xtd::tunit::tests {
  class test_class_(vvalid_are_equal_double_NaN_tests) {
  public:
    void test_method_(test_case_succeed) {
      double d = std::numeric_limits<double>::quiet_NaN();
      xtd::tunit::valid::are_equal(std::numeric_limits<double>::quiet_NaN(), d);
    }
  };
}

void test_(vvalid_are_equal_double_NaN_tests, test_output) {
  xtd::tunit::settings::default_settings().exit_status(0);
  xtd::tunit::settings::default_settings().filter_tests("vvalid_are_equal_double_NaN_tests.*");
  std::stringstream ss;
  xtd::tunit::unit_test(std::make_unique<assert_unit_tests::unit_tests_event_listener>(ss)).run();
  assert_value_("Start 1 test from 1 test case\n"
    "  SUCCEED vvalid_are_equal_double_NaN_tests.test_case_succeed\n"
    "End 1 test from 1 test case ran.\n", ss.str());
}

void test_(vvalid_are_equal_double_NaN_tests, test_result) {
  xtd::tunit::settings::default_settings().exit_status(0);
  xtd::tunit::settings::default_settings().filter_tests("vvalid_are_equal_double_NaN_tests.*");
  std::stringstream ss;
  assert_value_(0, xtd::tunit::unit_test(std::make_unique<assert_unit_tests::unit_tests_event_listener>(ss)).run());
}
