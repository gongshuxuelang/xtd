/// @file
/// @brief Contains xtd::as method.
#pragma once

/// @cond
#if !defined(__XTD_CORE_INTERNAL__)
#error "Do not include this file: Internal use only"
#endif
/// @endcond

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new int16 object converted from value.
  /// @exception xtd::invalid_cast_exception the parameters is bad cast.
  /// @par Header
  /// @code #include <xtd/as> @endcode
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// @code
  /// std::any value = true;
  /// int16 result = as<int16>(value);
  /// @endcode
  template<>
  inline int16 as<int16>(std::any value) {
    return xtd::convert::to_int16(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new int16 object converted from value.
  /// @par Header
  /// @code #include <xtd/as> @endcode
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// @code
  /// bool value = true;
  /// int16 result = as<int16>(value);
  /// @endcode
  template<>
  inline int16 as<int16>(bool value) {
    return xtd::convert::to_int16(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new int16 object converted from value.
  /// @par Header
  /// @code #include <xtd/as> @endcode
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// @code
  /// xtd::byte value = 42;
  /// int16 result = as<int16>(value);
  /// @endcode
  template<>
  inline int16 as<int16>(xtd::byte value) {
    return xtd::convert::to_int16(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new int16 object converted from value.
  /// @exception xtd::invalid_cast_exception throws always exception.
  /// @par Header
  /// @code #include <xtd/as> @endcode
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// @code
  /// char value = 'a';
  /// int16 result = as<int16>(value);
  /// @endcode
  template<>
  inline int16 as<int16>(char value) {
    return xtd::convert::to_int16(value);
  }
  
#if defined(__cpp_lib_char8_t)
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new int16 object converted from value.
  /// @exception xtd::invalid_cast_exception throws always exception.
  /// @par Header
  /// @code #include <xtd/as> @endcode
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// @code
  /// char8 value = u8'a';
  /// int16 result = as<int16>(value);
  /// @endcode
  template<>
  inline int16 as<int16>(char8 value) {
    return xtd::convert::to_int16(value);
  }
#endif
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new int16 object converted from value.
  /// @exception xtd::invalid_cast_exception throws always exception.
  /// @par Header
  /// @code #include <xtd/as> @endcode
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// @code
  /// char16 value = u'a';
  /// int16 result = as<int16>(value);
  /// @endcode
  template<>
  inline int16 as<int16>(char16 value) {
    return xtd::convert::to_int16(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new int16 object converted from value.
  /// @exception xtd::invalid_cast_exception throws always exception.
  /// @par Header
  /// @code #include <xtd/as> @endcode
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// @code
  /// char32 value = u'a';
  /// int16 result = as<int16>(value);
  /// @endcode
  template<>
  inline int16 as<int16>(char32 value) {
    return xtd::convert::to_int16(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new int16 object converted from value.
  /// @exception xtd::invalid_cast_exception throws always exception.
  /// @par Header
  /// @code #include <xtd/as> @endcode
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// @code
  /// wchar value = u'a';
  /// int16 result = as<int16>(value);
  /// @endcode
  template<>
  inline int16 as<int16>(wchar value) {
    return xtd::convert::to_int16(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new int16 object converted from value.
  /// @par Header
  /// @code #include <xtd/as> @endcode
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// @code
  /// decimal value = 42.50l;
  /// int16 result = as<int16>(value);
  /// @endcode
  template<>
  inline int16 as<int16>(decimal value) {
    return xtd::convert::to_int16(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new int16 object converted from value.
  /// @par Header
  /// @code #include <xtd/as> @endcode
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// @code
  /// double value = 42.50;
  /// int16 result = as<int16>(value);
  /// @endcode
  template<>
  inline int16 as<int16>(double value) {
    return xtd::convert::to_int16(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new int16 object converted from value.
  /// @par Header
  /// @code #include <xtd/as> @endcode
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// @code
  /// float value = 42.50f;
  /// int16 result = as<int16>(value);
  /// @endcode
  template<>
  inline int16 as<int16>(float value) {
    return xtd::convert::to_int16(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new int16 object converted from value.
  /// @par Header
  /// @code #include <xtd/as> @endcode
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// @code
  /// int16 value = 42;
  /// int16 result = as<int16>(value);
  /// @endcode
  template<>
  inline int16 as<int16>(int16 value) {
    return xtd::convert::to_int16(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new int16 object converted from value.
  /// @par Header
  /// @code #include <xtd/as> @endcode
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// @code
  /// int32 value = 42;
  /// int16 result = as<int16>(value);
  /// @endcode
  template<>
  inline int16 as<int16>(int32 value) {
    return xtd::convert::to_int16(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new int16 object converted from value.
  /// @par Header
  /// @code #include <xtd/as> @endcode
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// @code
  /// int64 value = 42l;
  /// int16 result = as<int16>(value);
  /// @endcode
  template<>
  inline int16 as<int16>(int64 value) {
    return xtd::convert::to_int16(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new int16 object converted from value.
  /// @par Header
  /// @code #include <xtd/as> @endcode
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// @code
  /// slong value = 42ll;
  /// int16 result = as<int16>(value);
  /// @endcode
  template<>
  inline int16 as<int16>(slong value) {
    return xtd::convert::to_int16(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new int16 object converted from value.
  /// @par Header
  /// @code #include <xtd/as> @endcode
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// @code
  /// sbyte value = 42ll;
  /// int16 result = as<int16>(value);
  /// @endcode
  template<>
  inline int16 as<int16>(sbyte value) {
    return xtd::convert::to_int16(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new int16 object converted from value.
  /// @par Header
  /// @code #include <xtd/as> @endcode
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// @code
  /// uint16 value = 42u;
  /// int16 result = as<int16>(value);
  /// @endcode
  template<>
  inline int16 as<int16>(uint16 value) {
    return xtd::convert::to_int16(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new int16 object converted from value.
  /// @par Header
  /// @code #include <xtd/as> @endcode
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// @code
  /// uint32 value = 42u;
  /// int16 result = as<int16>(value);
  /// @endcode
  template<>
  inline int16 as<int16>(uint32 value) {
    return xtd::convert::to_int16(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new int16 object converted from value.
  /// @par Header
  /// @code #include <xtd/as> @endcode
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// @code
  /// uint64 value = 42ul;
  /// int16 result = as<int16>(value);
  /// @endcode
  template<>
  inline int16 as<int16>(uint64 value) {
    return xtd::convert::to_int16(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new int16 object converted from value.
  /// @par Header
  /// @code #include <xtd/as> @endcode
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// @code
  /// xtd::ulong value = 42ull;
  /// int16 result = as<int16>(value);
  /// @endcode
  template<>
  inline int16 as<int16>(xtd::ulong value) {
    return xtd::convert::to_int16(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new int16 object converted from value.
  /// @exception xtd::argument_exception value does not represent a bool.
  /// @par Header
  /// @code #include <xtd/as> @endcode
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// @code
  /// ustring value = "42";
  /// int16 result = as<int16>(value);
  /// @endcode
  template<>
  inline int16 as<int16>(const xtd::ustring& value) {
    return xtd::convert::to_int16(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new int16 object converted from value.
  /// @exception xtd::argument_exception value does not represent a bool.
  /// @par Header
  /// @code #include <xtd/as> @endcode
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// @code
  /// ustring value = "42";
  /// int16 result = as<int16>(value);
  /// @endcode
  template<>
  inline int16 as<int16>(xtd::ustring& value) {
    return xtd::convert::to_int16(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @param from_base The base of the number in value, which must be 2, 8, 10, or 16.
  /// @return A new int16 object converted from value.
  /// @exception xtd::argument_exception value does not represent a int16.
  /// @par Header
  /// @code #include <xtd/as> @endcode
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// @code
  /// ustring value = "0x2A";
  /// int16 result = as<int16>(value, 16);
  /// @endcode
  template<>
  inline int16 as<int16>(const xtd::ustring& value, xtd::byte from_base) {
    return xtd::convert::to_int16(value, from_base);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new int16 object converted from value.
  /// @exception xtd::argument_exception value does not represent a bool.
  /// @par Header
  /// @code #include <xtd/as> @endcode
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// @code
  /// string value = "42";
  /// int16 result = as<int16>(value);
  /// @endcode
  template<>
  inline int16 as<int16>(const std::string& value) {
    return xtd::convert::to_int16(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new int16 object converted from value.
  /// @exception xtd::argument_exception value does not represent a bool.
  /// @par Header
  /// @code #include <xtd/as> @endcode
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// @code
  /// string value = "42";
  /// int16 result = as<int16>(value);
  /// @endcode
  template<>
  inline int16 as<int16>(std::string& value) {
    return xtd::convert::to_int16(value);
  }
  
#if defined(__cpp_lib_char8_t)
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new int16 object converted from value.
  /// @exception xtd::argument_exception value does not represent a bool.
  /// @par Header
  /// @code #include <xtd/as> @endcode
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// @code
  /// u8string value = u8"42";
  /// int16 result = as<int16>(value);
  /// @endcode
  template<>
  inline int16 as<int16>(const std::u8string& value) {
    return xtd::convert::to_int16(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new int16 object converted from value.
  /// @exception xtd::argument_exception value does not represent a bool.
  /// @par Header
  /// @code #include <xtd/as> @endcode
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// @code
  /// u8string value = u8"42";
  /// int16 result = as<int16>(value);
  /// @endcode
  template<>
  inline int16 as<int16>(std::u8string& value) {
    return xtd::convert::to_int16(value);
  }
#endif
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new int16 object converted from value.
  /// @exception xtd::argument_exception value does not represent a bool.
  /// @par Header
  /// @code #include <xtd/as> @endcode
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// @code
  /// u16string value = u"42";
  /// int16 result = as<int16>(value);
  /// @endcode
  template<>
  inline int16 as<int16>(const std::u16string& value) {
    return xtd::convert::to_int16(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new int16 object converted from value.
  /// @exception xtd::argument_exception value does not represent a bool.
  /// @par Header
  /// @code #include <xtd/as> @endcode
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// @code
  /// u16string value = u"42";
  /// int16 result = as<int16>(value);
  /// @endcode
  template<>
  inline int16 as<int16>(std::u16string& value) {
    return xtd::convert::to_int16(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new int16 object converted from value.
  /// @exception xtd::argument_exception value does not represent a bool.
  /// @par Header
  /// @code #include <xtd/as> @endcode
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// @code
  /// u32string value = U"42";
  /// int16 result = as<int16>(value);
  /// @endcode
  template<>
  inline int16 as<int16>(const std::u32string& value) {
    return xtd::convert::to_int16(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new int16 object converted from value.
  /// @exception xtd::argument_exception value does not represent a bool.
  /// @par Header
  /// @code #include <xtd/as> @endcode
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// @code
  /// u32string value = U"42";
  /// int16 result = as<int16>(value);
  /// @endcode
  template<>
  inline int16 as<int16>(std::u32string& value) {
    return xtd::convert::to_int16(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new int16 object converted from value.
  /// @exception xtd::argument_exception value does not represent a bool.
  /// @par Header
  /// @code #include <xtd/as> @endcode
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// @code
  /// wstring value = L"42";
  /// int16 result = as<int16>(value);
  /// @endcode
  template<>
  inline int16 as<int16>(const std::wstring& value) {
    return xtd::convert::to_int16(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new int16 object converted from value.
  /// @exception xtd::argument_exception value does not represent a bool.
  /// @par Header
  /// @code #include <xtd/as> @endcode
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// @code
  /// wstring value = L"42";
  /// int16 result = as<int16>(value);
  /// @endcode
  template<>
  inline int16 as<int16>(std::wstring& value) {
    return xtd::convert::to_int16(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new int16 object converted from value.
  /// @exception xtd::argument_exception value does not represent a bool.
  /// @par Header
  /// @code #include <xtd/as> @endcode
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// @code
  /// const char* value = "42";
  /// int16 result = as<int16>(value);
  /// @endcode
  template<>
  inline int16 as<int16>(const char* value) {
    return xtd::convert::to_int16(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new int16 object converted from value.
  /// @exception xtd::argument_exception value does not represent a bool.
  /// @par Header
  /// @code #include <xtd/as> @endcode
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// @code
  /// char* value = "42";
  /// int16 result = as<int16>(value);
  /// @endcode
  template<>
  inline int16 as<int16>(char* value) {
    return xtd::convert::to_int16(value);
  }
  
#if defined(__cpp_lib_char8_t)
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new int16 object converted from value.
  /// @exception xtd::argument_exception value does not represent a bool.
  /// @par Header
  /// @code #include <xtd/as> @endcode
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// @code
  /// const char8* value = u8"42";
  /// int16 result = as<int16>(value);
  /// @endcode
  template<>
  inline int16 as<int16>(const char8* value) {
    return xtd::convert::to_int16(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new int16 object converted from value.
  /// @exception xtd::argument_exception value does not represent a bool.
  /// @par Header
  /// @code #include <xtd/as> @endcode
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// @code
  /// char8* value = u8"42";
  /// int16 result = as<int16>(value);
  /// @endcode
  template<>
  inline int16 as<int16>(char8* value) {
    return xtd::convert::to_int16(value);
  }
#endif
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new int16 object converted from value.
  /// @exception xtd::argument_exception value does not represent a bool.
  /// @par Header
  /// @code #include <xtd/as> @endcode
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// @code
  /// const char16* value = u"42";
  /// int16 result = as<int16>(value);
  /// @endcode
  template<>
  inline int16 as<int16>(const char16* value) {
    return xtd::convert::to_int16(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new int16 object converted from value.
  /// @exception xtd::argument_exception value does not represent a bool.
  /// @par Header
  /// @code #include <xtd/as> @endcode
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// @code
  /// char16* value = u"42";
  /// int16 result = as<int16>(value);
  /// @endcode
  template<>
  inline int16 as<int16>(char16* value) {
    return xtd::convert::to_int16(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new int16 object converted from value.
  /// @exception xtd::argument_exception value does not represent a bool.
  /// @par Header
  /// @code #include <xtd/as> @endcode
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// @code
  /// const char32* value = U"42";
  /// int16 result = as<int16>(value);
  /// @endcode
  template<>
  inline int16 as<int16>(const char32* value) {
    return xtd::convert::to_int16(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new int16 object converted from value.
  /// @exception xtd::argument_exception value does not represent a bool.
  /// @par Header
  /// @code #include <xtd/as> @endcode
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// @code
  /// char32* value = U"42";
  /// int16 result = as<int16>(value);
  /// @endcode
  template<>
  inline int16 as<int16>(char32* value) {
    return xtd::convert::to_int16(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new int16 object converted from value.
  /// @exception xtd::argument_exception value does not represent a bool.
  /// @par Header
  /// @code #include <xtd/as> @endcode
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// @code
  /// const wchar* value = L"42";
  /// int16 result = as<int16>(value);
  /// @endcode
  template<>
  inline int16 as<int16>(const wchar* value) {
    return xtd::convert::to_int16(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new int16 object converted from value.
  /// @exception xtd::argument_exception value does not represent a bool.
  /// @par Header
  /// @code #include <xtd/as> @endcode
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// @code
  /// wchar* value = L"42";
  /// int16 result = as<int16>(value);
  /// @endcode
  template<>
  inline int16 as<int16>(wchar* value) {
    return xtd::convert::to_int16(value);
  }
}
