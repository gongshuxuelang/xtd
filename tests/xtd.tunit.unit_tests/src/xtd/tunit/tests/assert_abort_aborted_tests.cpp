#include "../../../assert_unit_tests/assert_unit_tests.h"
#include <xtd/xtd.tunit>

namespace xtd::tunit::tests {
  class test_class_(assert_abort_aborted_tests) {
  public:
    void test_method_(test_case_aborted) {
      xtd::tunit::assert::abort(xtd::diagnostics::stack_frame {"assert_abort_aborted_tests.cpp", 8});
    }
  };
}

void test_(assert_abort_aborted_tests, test_output) {
  auto [result, output] = run_test_("assert_abort_aborted_tests.*");
  assert_value_("Start 1 test from 1 test case\n"
    "  ABORTED assert_abort_aborted_tests.test_case_aborted\n"
    "    Test aborted\n"
    "End 1 test from 1 test case ran.\n", output);
}

void test_(assert_abort_aborted_tests, test_result) {
  auto [result, output] = run_test_("assert_abort_aborted_tests.*");
  assert_value_(0, result);
}
