#include <xtd/threading/timeout.h>
#include <xtd/xtd.tunit>

using namespace xtd::threading;
using namespace xtd::tunit;

namespace xtd::tests {
  class test_class_(timeout_tests) {
  public:
    void test_method_(infinite) {
      assert::are_equal(-1, timeout::infinite, csf_);
    }

    void test_method_(infinite_time_span) {
      assert::are_equal(time_span {-1}, timeout::infinite_time_span, csf_);
    }
  };
}