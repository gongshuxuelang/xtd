#include <xtd/language_id.h>
#include <xtd/xtd.tunit>

using namespace xtd;
using namespace xtd::tunit;

namespace xtd::tests {
  class test_class_(language_id_tests) {
  public:
    void test_method_(unknown) {
      assert::are_equal(-1, enum_object<>::to_int32(language_id::unknown), csf_);
      assert::are_equal("unknown", enum_object<>::to_string(language_id::unknown), csf_);
      assert::are_equal(language_id::unknown, enum_object<>::parse<language_id>("unknown"), csf_);
    }
    
    void test_method_(cpp_pre98) {
      assert::are_equal(0, enum_object<>::to_int32(language_id::cpp_pre98), csf_);
      assert::are_equal("cpp_pre98", enum_object<>::to_string(language_id::cpp_pre98), csf_);
      assert::are_equal(language_id::cpp_pre98, enum_object<>::parse<language_id>("cpp_pre98"), csf_);
    }
    
    void test_method_(cpp98) {
      assert::are_equal(1, enum_object<>::to_int32(language_id::cpp98), csf_);
      assert::are_equal("cpp98", enum_object<>::to_string(language_id::cpp98), csf_);
      assert::are_equal(language_id::cpp98, enum_object<>::parse<language_id>("cpp98"), csf_);
    }
    
    void test_method_(cpp11) {
      assert::are_equal(2, enum_object<>::to_int32(language_id::cpp11), csf_);
      assert::are_equal("cpp11", enum_object<>::to_string(language_id::cpp11), csf_);
      assert::are_equal(language_id::cpp11, enum_object<>::parse<language_id>("cpp11"), csf_);
    }
    
    void test_method_(cpp14) {
      assert::are_equal(3, enum_object<>::to_int32(language_id::cpp14), csf_);
      assert::are_equal("cpp14", enum_object<>::to_string(language_id::cpp14), csf_);
      assert::are_equal(language_id::cpp14, enum_object<>::parse<language_id>("cpp14"), csf_);
    }
    
    void test_method_(cpp17) {
      assert::are_equal(4, enum_object<>::to_int32(language_id::cpp17), csf_);
      assert::are_equal("cpp17", enum_object<>::to_string(language_id::cpp17), csf_);
      assert::are_equal(language_id::cpp17, enum_object<>::parse<language_id>("cpp17"), csf_);
    }
    
    void test_method_(cpp20) {
      assert::are_equal(5, enum_object<>::to_int32(language_id::cpp20), csf_);
      assert::are_equal("cpp20", enum_object<>::to_string(language_id::cpp20), csf_);
      assert::are_equal(language_id::cpp20, enum_object<>::parse<language_id>("cpp20"), csf_);
    }
    
    void test_method_(cpp23) {
      assert::are_equal(6, enum_object<>::to_int32(language_id::cpp23), csf_);
      assert::are_equal("cpp23", enum_object<>::to_string(language_id::cpp23), csf_);
      assert::are_equal(language_id::cpp23, enum_object<>::parse<language_id>("cpp23"), csf_);
    }
  };
}