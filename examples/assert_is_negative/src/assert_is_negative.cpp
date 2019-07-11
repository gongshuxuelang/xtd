#include <xtd/xtd.tunit>
#include <iterator>
#include <string>

using namespace std;
using namespace xtd::tunit;

namespace unit_tests {
  class test_class_(test) {
  public:
    void test_method_(test_case_succeed) {
      int i = -1;
      assert::is_negative(i);
    }

    void test_method_(test_case_failed) {
      int i = 1;
      assert::is_negative(i);
    }
  };
}

// The main entry point for the application.
int main() {
  return console_unit_test().run();
}

// This code produces the following output:
//
// Start 2 tests from 1 test case
// Run tests:
//   SUCCEED test.test_case_succeed (0 ms total)
//   FAILED  test.test_case_failed (0 ms total)
//     Expected: negative
//     But was:  1
//     Stack Trace: in |---OMITTED---|/assert_is_negative.cpp:16
//
// Test results:
//   SUCCEED 1 test.
//   FAILED  1 test.
// End 2 tests from 1 test case ran. (0 ms total)
