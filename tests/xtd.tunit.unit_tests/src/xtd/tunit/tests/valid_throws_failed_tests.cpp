#include "../../../assert_unit_tests/assert_unit_tests.h"
#include <xtd/xtd.tunit>
#include <vector>

namespace xtd::tunit::tests {
  class test_class_(valid_throws_failed_tests) {
  public:
    void test_method_(test_case_failed) {
      std::vector v = {1, 2, 3, 4};
      xtd::tunit::valid::throws<std::out_of_range>([&] {v.at(2);});
    }
  };
}

void test_(valid_throws_failed_tests, test_output) {
  auto [result, output] = run_test_("valid_throws_failed_tests.*");
  assert_value_("Start 1 test from 1 test case\n"
    "  FAILED  valid_throws_failed_tests.test_case_failed\n"
    "    Expected: <std::out_of_range>\n"
    "    But was:  <nothing>\n"
    "End 1 test from 1 test case ran.\n", output);
}

void test_(valid_throws_failed_tests, test_result) {
  auto [result, output] = run_test_("valid_throws_failed_tests.*");
  assert_value_(1, result);
}
