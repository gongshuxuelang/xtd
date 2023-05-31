#include "../../../assert_unit_tests/assert_unit_tests.h"
#include <xtd/xtd.tunit>

namespace xtd::tunit::tests {
  class test_class_(file_assert_are_equal_istream_failed_tests) {
  public:
    void test_method_(test_case_lenght_failed) {
      // As the xtd::tunit::file_assert::are_equal method uses std::istream and not std::ifstream, the test can be performed with std::istringstream.
      xtd::tunit::file_assert::are_equal(std::istringstream("Test xtd::tunit::file_assert::are_equal."), std::istringstream("Test xtd::tunit::file_assert::are_equa."));
    }
    
    void test_method_(test_case_letter_failed) {
      // As the xtd::tunit::file_assert::are_equal method uses std::istream and not std::ifstream, the test can be performed with std::istringstream.
      xtd::tunit::file_assert::are_equal(std::istringstream("Test xtd::tunit::file_assert::are_equal."), std::istringstream("Test xtd::tunit::Dile_assert::are_equal."));
    }
  };
}

void test_(file_assert_are_equal_istream_failed_tests, test_output) {
  auto [result, output] = run_test_("file_assert_are_equal_istream_failed_tests.*");
  assert_value_("Start 2 tests from 1 test case\n"
    "  FAILED  file_assert_are_equal_istream_failed_tests.test_case_lenght_failed\n"
    "    Expected: istream length 40\n"
    "    But was:  39\n"
    "  FAILED  file_assert_are_equal_istream_failed_tests.test_case_letter_failed\n"
    "    Expected: istream at offset 17 value f\n"
    "    But was:  D\n"
    "End 2 tests from 1 test case ran.\n", output);
}

void test_(file_assert_are_equal_istream_failed_tests, test_result) {
  auto [result, output] = run_test_("file_assert_are_equal_istream_failed_tests.*");
  assert_value_(1, result);
}
