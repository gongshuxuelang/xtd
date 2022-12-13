/// @file
/// @brief Contains xtd::enum_object.
/// @copyright Copyright (c) 2022 Gammasoft. All rights reserved.
#pragma once

#include <optional>
#include "enum_attribute.h"
#include "format_exception.h"
#include "icomparable.h"
#include "iequatable.h"
#include "number_styles.h"
#include "static.h"
#include "string_comparison.h"
#include "string_split_options.h"
#include "enum_collection.h"
#include "enum_register.h"
#include "enum_set_attribute.h"
/// @cond
#define __XTD_CORE_INTERNAL__
#include "internal/__enum_definition_to_enum_collection.h"
#undef __XTD_CORE_INTERNAL__
/// @endcond

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief Provides the base class for enumerations.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core system
  /// @remarks For more information about enumeration, see <a href="https://github.com/gammasoft71/xtd/blob/master/docs/enum_class.md">enum class</a> guide.
  /// The following code show how to use xtd::enum_object class for an enum.
  /// @include enum_class.cpp
  /// The following code show how to use xtd::enum_object class for an enum flags.
  /// @include enum_class_flags.cpp
  template<typename enum_t = std::nullptr_t>
  class enum_object : public xtd::object, public xtd::icomparable<enum_object<enum_t>>, public xtd::iequatable<enum_object<enum_t>> {
  public:
    /// @name Alias
    
    /// @{
    using enum_type = enum_t;
    /// @}
    
    /// @name Constructors
    
    /// @{
    /// @brief Initializes a new instance of the xtd::enum_object class.
    enum_object() noexcept = default;
    /// @brief Initializes a new instance of the xtd::enum_object class with specified value.
    /// @param value Value to set to this instance.
    enum_object(enum_type value) : value_(value) {}
    /// @}
    
    /// @cond
    enum_object(xtd::byte value) : value_(to_enum(value)) {}
    enum_object(sbyte value) : value_(to_enum(value)) {}
    enum_object(int16 value) : value_(to_enum(value)) {}
    enum_object(int32 value) : value_(to_enum(value)) {}
    enum_object(int64 value) : value_(to_enum(value)) {}
    enum_object(uint16 value) : value_(to_enum(value)) {}
    enum_object(uint32 value) : value_(to_enum(value)) {}
    enum_object(uint64 value) : value_(to_enum(value)) {}
    enum_object(enum_object&&) noexcept = default;
    enum_object(const enum_object&) noexcept = default;
    enum_object& operator =(const enum_object&) noexcept = default;
    operator enum_type() const noexcept {return value_;}
    /// @endcond
    
    /// @name Public properties
    
    /// @{
    /// @brief Retrieves an array of the values of the constants in a specified enumeration.
    /// @param flag An enumeration value.
    /// @return true if the bit field or bit fields that are set in flag are also set in the current instance; otherwise, false.
    /// @remarks The has_flag method returns the result of the following bool expression : this_instance And flag = flag
    bool has_flag(enum_type flag) const noexcept {return (to_int(value_) & to_int(flag)) == to_int(flag);}
    
    /// @brief Gets the value of the enum.
    /// @return The value of the enum.
    enum_type value() const noexcept {return value_;}
    /// @brief Sets the value of the enum.
    /// @param value The value of the enum.
    enum_object& value(enum_type value) {
      value_ = value;
      return *this;
    }
    /// @}
    
    /// @name Public methods
    
    /// @{
    int32 compare_to(const enum_object& value) const noexcept override {
      if (to_int(value_) == to_int(value.value_)) return 0;
      if (to_int(value_) < to_int(value.value_)) return -1;
      return 1;
    }
        
    /// @brief Converts this instance to byte.
    /// @return A new xtd::byte object converted from this instance.
    xtd::byte to_byte() const noexcept {return static_cast<xtd::byte>(value_);}
    
    /// @brief Converts this instance to int16.
    /// @return A new to_int16 object converted from this instance.
    int16 to_int16() const noexcept {return static_cast<int16>(value_);}
    
    /// @brief Converts this instance to int32.
    /// @return A new to_int32 object converted from this instance.
    int32 to_int32() const noexcept {return static_cast<int32>(value_);}
    
    /// @brief Converts this instance to int64.
    /// @return A new to_int64 object converted from this instance.
    int64 to_int64() const noexcept {return static_cast<int64>(value_);}
    
    /// @brief Converts this instance to signed byte.
    /// @return A new sbyte object converted from this instance.
    sbyte to_sbyte() const noexcept {return static_cast<sbyte>(value_);}
    
    /// @brief Converts this instance to unsigned int16.
    /// @return A new to_uint16 object converted from this instance.
    uint16 to_uint16() const noexcept {return static_cast<uint16>(value_);}
    
    /// @brief Converts this instance to unsigned int32.
    /// @return A new to_uint32 object converted from this instance.
    uint32 to_uint32() const noexcept {return static_cast<uint32>(value_);}
    
    /// @brief Converts this instance to unsigned int64.
    /// @return A new to_uint64 object converted from this instance.
    uint64 to_uint64() const noexcept {return static_cast<uint64>(value_);}
    
    xtd::ustring to_string() const noexcept override {
      init();
      if (attribute() == xtd::enum_attribute::flags) return to_string_flags();
      
      auto iterator = std::find_if(entries().begin(), entries().end(), [&](auto value)->bool {return value.first == value_;});
      if (iterator == entries().end()) return ustring::format("{}", to_int(value_));
      
      return iterator->second;
    }
    
    /// @brief Converts the value of this instance to its equivalent string representation using the specified format.
    /// @param format A format string.
    /// @return The string representation of the value of this instance as specified by format.
    /// @exception xtd::format_exception format contains an invalid specification.
    /// @remarks The format parameter can be one of the following format strings: "G" or "g", "D" or "d", "X" or "x", and "F" or "f" (the format string is not case-sensitive). If format is null or an empty string (""), the general format specifier ("G") is used. For more information about the enumeration format strings and formatting enumeration values, see <a href="https://github.com/gammasoft71/xtd/blob/master/docs/format_enumeration_format_strings.md">Enumeration Format Strings</a>. For more information about formatting in general, see <a href="https://github.com/gammasoft71/xtd/blob/master/docs/format_overview.md">Formatting Types</a>.
    /// @par Notes to caller
    /// If multiple enumeration members have the same underlying value and you attempt to retrieve the string representation of an enumeration member's name based on its underlying value, your code should not make any assumptions about which name the method will return. For example, the following enumeration defines two members, shade::gray and shade::grey, that have the same underlying value.
    /// @code
    /// enum shade {
    ///   white = 0, gray = 1, grey = 1, black = 2
    /// };
    /// @endcode
    /// The following method call attempts to retrieve the name of a member of the shade enumeration whose underlying value is 1. The method can return either "gray" or "grey", and your code should not make any assumptions about which string will be returned.
    /// @code
    /// ustring shade_name = enum_object<shade>(as<shade>(1)).to_string("F");
    /// @endcode
    xtd::ustring to_string(const xtd::ustring& format) const {
      init();
      auto fmt = format;
      if (fmt.empty()) fmt =  "G";
      
      switch (fmt[0]) {
        case 'b':
        case 'B':
        case 'd':
        case 'D':
        case 'o':
        case 'O':
        case 'x':
        case 'X': return __numeric_formatter(fmt, static_cast<long long int>(value_), std::locale());
        case 'f':
        case 'F':
        case 'g':
        case 'G': return __format_stringer<char>(value_);
      }
      throw format_exception("Invalid format");
    }
    /// @}
    
    /// @cond
    bool equals(const enum_object& value) const noexcept override {return value_ == value.value_;}
    bool equals(enum_type value) const noexcept {return value_ == value;}
    template<typename attribute_t>
    bool equals(attribute_t value) const noexcept {return false;}
    
    static enum_type parse(const xtd::ustring& str) {return parse(str, false);}
    static enum_type parse(const xtd::ustring& str, bool ignore_case) {
      enum_object<enum_type>().init();
      if (enum_object<enum_type>().attribute() == xtd::enum_attribute::flags) return parse_flags(str, ignore_case);
      
      for (auto item : enum_object<enum_type>().entries()) {
        if (xtd::ustring::compare(str, item.second, ignore_case) == 0)
          return (enum_type)item.first;
      }
      
      return to_enum(xtd::parse<int64>(str));
    }
    
    static enum_type parse_flags(const xtd::ustring& value, bool ignore_case) {
      std::vector<xtd::ustring> values = value.split({','});
      for (xtd::ustring& str : values)
        str = str.trim_start(' ').trim_end(' ');
      
      if (values.size() == 1) {
        for (auto item : enum_object<enum_type>().entries()) {
          if (xtd::ustring::compare(value, item.second, ignore_case) == 0)
            return to_enum(item.first);
        }
        return to_enum(xtd::parse<int64>(value));
      }
      
      int64 result = 0;
      for (xtd::ustring str : values) {
        bool found = false;
        for (auto item : enum_object<enum_type>().entries()) {
          if (xtd::ustring::compare(str, item.second, ignore_case) == 0) {
            found = true;
            result |= to_int(item.first);
            break;
          }
        }
        if (found == false)
          throw xtd::format_exception(csf_);
      }
      
      return to_enum(result);
    }
    
    /// @endcond
    
  private:
    friend class enum_object<std::nullptr_t>;
    
    xtd::ustring get_name() const noexcept {
      auto iterator = std::find_if(entries().begin(), entries().end(), [&](auto value)->bool {return value.first == value_;});
      if (iterator == entries().end()) return xtd::ustring::format("{}", to_int(value_));
      return iterator->second;
    }
    
    xtd::ustring to_string_flags() const noexcept {
      auto iterator = std::find_if(entries().begin(), entries().end(), [&](auto value)->bool {return value.first == value_;});
      if (to_int(value_) == 0 && iterator == entries().end()) return "0";
      
      iterator = std::find_if(entries().begin(), entries().end(), [&](auto value)->bool {return value.first == to_enum(0);});
      if (to_int(value_) == 0) return iterator == entries().end() ? "0" : iterator->second;
      
      xtd::ustring str;
      int64 rest = to_int(value_);
      enum_collection<enum_type> reversed = entries();
      std::reverse(reversed.begin(), reversed.end());
      
      for (auto item : reversed) {
        if (to_int(item.first) != 0 && (rest & to_int(item.first)) == to_int(item.first)) {
          rest -= to_int(item.first);
          if (!xtd::ustring::is_empty(str)) str = ", " + str;
          str = item.second + str;
        }
      }
      
      if (str.empty() || rest > 0) return  xtd::ustring::format("{}", to_int(value_));
      
      return str;
    }
    
    template<typename attribute_t>
    static enum_type to_enum(attribute_t value) noexcept {return (enum_type)value;}
    static int64 to_int(enum_type value) noexcept {return static_cast<int64>(value);}
    
    static xtd::enum_attribute attribute() noexcept {
      if (attribute_.has_value()) return attribute_.value();
      attribute_ = xtd::enum_attribute(enum_set_attribute<enum_type>());
      return attribute_.value();
    }
    
    static enum_collection<enum_type>& entries() noexcept {
      if (entries_.has_value()) return entries_.value();
      entries_ = enum_collection<enum_type>(enum_register<enum_type>());
      return entries_.value();
    };
    
    static void init() noexcept {
      attribute();
      entries();
    }
    
    inline static std::optional<xtd::enum_attribute> attribute_;
    inline static std::optional<enum_collection<enum_type>> entries_;
    enum_type value_ {};
  };
  
  /// @brief Provides the base class for enumerations.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core system
  template<>
  class enum_object<std::nullptr_t> static_ {
  public:
    /// @brief Retrieves an array of the std::pair<enum_t, xtd::ustring> of the constants in a specified enumeration.
    /// @return A xtd::ustring array of the values and names of the constants in enumType.
    template<typename enum_t>
    static const xtd::enum_collection<enum_t>& get_entries() noexcept {
      return enum_object<enum_t>().entries();
    }
    
    /// @brief Retrieves an array of the std::pair<xtd::byte, xtd::ustring> of the constants in a specified enumeration.
    /// @return A xtd::ustring array of the values and names of the constants in enumType.
    template<typename enum_t>
    static xtd::enum_collection<xtd::byte> get_entries_as_byte() noexcept {
      xtd::enum_collection<xtd::byte> entries;
      for (auto entry : enum_object<enum_t>().entries())
        entries.emplace_back(enum_object<enum_t>(entry.first).to_byte(), entry.second);
      return entries;
    }
    
    /// @brief Retrieves an array of the std::pair<int16, xtd::ustring> of the constants in a specified enumeration.
    /// @return A xtd::ustring array of the values and names of the constants in enumType.
    template<typename enum_t>
    static xtd::enum_collection<int16> get_entries_as_int16() noexcept {
      xtd::enum_collection<int16> entries;
      for (auto entry : enum_object<enum_t>().entries())
        entries.emplace_back(enum_object<enum_t>(entry.first).to_int16(), entry.second);
      return entries;
    }
    
    /// @brief Retrieves an array of the std::pair<int32, xtd::ustring> of the constants in a specified enumeration.
    /// @return A xtd::ustring array of the values and names of the constants in enumType.
    template<typename enum_t>
    static xtd::enum_collection<int32> get_entries_as_int32() noexcept {
      xtd::enum_collection<int32> entries;
      for (auto entry : enum_object<enum_t>().entries())
        entries.emplace_back(enum_object<enum_t>(entry.first).to_int32(), entry.second);
      return entries;
    }
    
    /// @brief Retrieves an array of the std::pair<int64, xtd::ustring> of the constants in a specified enumeration.
    /// @return A xtd::ustring array of the values and names of the constants in enumType.
    template<typename enum_t>
    static xtd::enum_collection<int64> get_entries_as_int64() noexcept {
      xtd::enum_collection<int64> entries;
      for (auto entry : enum_object<enum_t>().entries())
        entries.emplace_back(enum_object<enum_t>(entry.first).to_int64(), entry.second);
      return entries;
    }
    
    /// @brief Retrieves an array of the std::pair<sbyte, xtd::ustring> of the constants in a specified enumeration.
    /// @return A xtd::ustring array of the values and names of the constants in enumType.
    template<typename enum_t>
    static xtd::enum_collection<sbyte> get_entries_as_sbyte() noexcept {
      xtd::enum_collection<sbyte> entries;
      for (auto entry : enum_object<enum_t>().entries())
        entries.emplace_back(enum_object<enum_t>(entry.first).to_sbyte(), entry.second);
      return entries;
    }
    
    /// @brief Retrieves an array of the std::pair<uint16, xtd::ustring> of the constants in a specified enumeration.
    /// @return A xtd::ustring array of the values and names of the constants in enumType.
    template<typename enum_t>
    static xtd::enum_collection<uint16> get_entries_as_uint16() noexcept {
      xtd::enum_collection<uint16> entries;
      for (auto entry : enum_object<enum_t>().entries())
        entries.emplace_back(enum_object<enum_t>(entry.first).to_int16(), entry.second);
      return entries;
    }
    
    /// @brief Retrieves an array of the std::pair<uint32, xtd::ustring> of the constants in a specified enumeration.
    /// @return A xtd::ustring array of the values and names of the constants in enumType.
    template<typename enum_t>
    static xtd::enum_collection<uint32> get_entries_as_uint32() noexcept {
      xtd::enum_collection<uint32> entries;
      for (auto entry : enum_object<enum_t>().entries())
        entries.emplace_back(enum_object<enum_t>(entry.first).to_uint32(), entry.second);
      return entries;
    }
    
    /// @brief Retrieves an array of the std::pair<uint64, xtd::ustring> of the constants in a specified enumeration.
    /// @return A xtd::ustring array of the values and names of the constants in enumType.
    template<typename enum_t>
    static xtd::enum_collection<uint64> get_entries_as_uint64() noexcept {
      xtd::enum_collection<uint64> entries;
      for (auto entry : enum_object<enum_t>().entries())
        entries.emplace_back(enum_object<enum_t>(entry.first).to_uint64(), entry.second);
      return entries;
    }
    
    /// @brief Retrieves the name of the constant in the specified enumeration that has the specified value.
    /// @param value The value of a particular enumerated constant in terms of its underlying type.
    /// @return A xtd::ustring containing the name of the enumerated constant in enumType whose value is value; or the value int32 to xtd::ustring if no such constant is found.
    /// @exception xtd::argument_exception The value is ! a value of enumType.
    template<typename enum_t>
    static xtd::ustring get_name(enum_t value) noexcept {return enum_object<enum_t>(value).to_string();}
    /// @brief Retrieves the name of the constant in the specified enumeration that has the specified value.
    /// @param value The value of a particular enumerated constant in terms of its underlying type.
    /// @return xtd::ustring A xtd::ustring containing the name of the enumerated constant in enumType whose value is value; or the value int32 to xtd::ustring if no such constant is found.
    /// @exception xtd::argument_exception The value is ! a value of enumType.
    template<typename enum_t>
    static xtd::ustring get_name(enum_object<enum_t> value) noexcept {return enum_object<enum_t>(value).to_string();}
    /// @brief Retrieves the name of the constant in the specified enumeration that has the specified value.
    /// @param value The value of a particular enumerated constant in terms of its underlying type.
    /// @return xtd::ustring A xtd::ustring containing the name of the enumerated constant in enumType whose value is value; or the value int32 to xtd::ustring if no such constant is found.
    /// @exception xtd::argument_exception The value is ! a value of enumType.
    template<typename enum_t>
    static xtd::ustring get_name(int32 value) noexcept {return enum_object<enum_t>(value).to_string();}
    /// @brief Retrieves the name of the constant in the specified enumeration that has the specified value.
    /// @param value The value of a particular enumerated constant in terms of its underlying type.
    /// @return A xtd::ustring containing the name of the enumerated constant in enumType whose value is value; or the value int32 to xtd::ustring if no such constant is found.
    /// @exception xtd::argument_exception The value is ! a value of enumType.
    template<typename enum_t>
    static xtd::ustring get_name(int64 value) noexcept {return enum_object<enum_t>(value).to_string();}
    
    /// @brief Retrieves an array of the names of the constants in a specified enumeration.
    /// @return std::vector<xtd::ustring> A xtd::ustring array of the names of the constants in enumType.
    /// @exception xtd::argument_exception The value is ! a value of enumType.
    template<typename enum_t>
    static std::vector<xtd::ustring> get_names() noexcept {
      std::vector<xtd::ustring> names;
      for (auto entry : enum_object<enum_t>().entries())
        names.push_back(entry.second);
      return names;
    }
    
    /// @brief Retrieves an array of the values of the constants in a specified enumeration.
    /// @return Array<enum_t> An array that contains the values of the constants in enumType.
    /// @exception xtd::argument_exception The value is ! a value of enumType.
    template<typename enum_t>
    static std::vector<enum_t> get_values() noexcept {
      std::vector<enum_t> values;
      for (auto entry : enum_object<enum_t>().entries())
        values.push_back(entry);
      return values;
    }
    
    /// @brief Retrieves an array of the values of the constants in a specified enumeration.
    /// @return Array<xtd::byte> An array that contains the values of the constants in enumType.
    /// @exception xtd::argument_exception The value is ! a value of enumType.
    template<typename enum_t>
    static std::vector<xtd::byte> get_values_as_byte() noexcept {
      std::vector<xtd::byte> values;
      for (auto entry : enum_object<enum_t>().entries())
        values.push_back(enum_object<enum_t>(entry.first).to_byte());
      return values;
    }
    
    /// @brief Retrieves an array of the values of the constants in a specified enumeration.
    /// @return Array<int16> An array that contains the values of the constants in enumType.
    /// @exception xtd::argument_exception The value is ! a value of enumType.
    template<typename enum_t>
    static std::vector<int16> get_values_as_int16() noexcept {
      std::vector<int16> values;
      for (auto entry : enum_object<enum_t>().entries())
        values.push_back(enum_object<enum_t>(entry.first).to_int16());
      return values;
    }
    
    /// @brief Retrieves an array of the values of the constants in a specified enumeration.
    /// @return Array<int32> An array that contains the values of the constants in enumType.
    /// @exception xtd::argument_exception The value is ! a value of enumType.
    template<typename enum_t>
    static std::vector<int32> get_values_as_int32() noexcept {
      std::vector<int32> values;
      for (auto entry : enum_object<enum_t>().entries())
        values.push_back(enum_object<enum_t>(entry.first).to_int32());
      return values;
    }
    
    /// @brief Retrieves an array of the values of the constants in a specified enumeration.
    /// @return Array<int64> An array that contains the values of the constants in enumType.
    /// @exception xtd::argument_exception The value is ! a value of enumType.
    template<typename enum_t>
    static std::vector<int64> get_values_as_int64() noexcept {
      std::vector<int64> values;
      for (auto entry : enum_object<enum_t>().entries())
        values.push_back(enum_object<enum_t>(entry.first).to_int64());
      return values;
    }
    
    /// @brief Retrieves an array of the values of the constants in a specified enumeration.
    /// @return Array<sbyte> An array that contains the values of the constants in enumType.
    /// @exception xtd::argument_exception The value is ! a value of enumType.
    template<typename enum_t>
    static std::vector<sbyte> get_values_as_sbyte() noexcept {
      std::vector<sbyte> values;
      for (auto entry : enum_object<enum_t>().entries())
        values.push_back(enum_object<enum_t>(entry.first).to_sbyte());
      return values;
    }
    
    /// @brief Retrieves an array of the values of the constants in a specified enumeration.
    /// @return Array<uint16> An array that contains the values of the constants in enumType.
    /// @exception xtd::argument_exception The value is ! a value of enumType.
    template<typename enum_t>
    static std::vector<uint16> get_values_as_uint16() noexcept {
      std::vector<uint16> values;
      for (auto entry : enum_object<enum_t>().entries())
        values.push_back(enum_object<enum_t>(entry.first).to_uint16());
      return values;
    }
    
    /// @brief Retrieves an array of the values of the constants in a specified enumeration.
    /// @return Array<uint32> An array that contains the values of the constants in enumType.
    /// @exception xtd::argument_exception The value is ! a value of enumType.
    template<typename enum_t>
    static std::vector<uint32> get_values_as_uint32() noexcept {
      std::vector<uint32> values;
      for (auto entry : enum_object<enum_t>().entries())
        values.push_back(enum_object<enum_t>(entry.first).to_uint32());
      return values;
    }
    
    /// @brief Retrieves an array of the values of the constants in a specified enumeration.
    /// @return Array<uint64> An array that contains the values of the constants in enumType.
    /// @exception xtd::argument_exception The value is ! a value of enumType.
    template<typename enum_t>
    static std::vector<uint64> get_values_as_uint64() noexcept {
      std::vector<uint64> values;
      for (auto entry : enum_object<enum_t>().entries())
        values.push_back(enum_object<enum_t>(entry.first).to_uint64());
      return values;
    }
    
    /// @brief Returns an indication whether a constant with a specified value exists in a specified enumeration.
    /// @param fromValue An enumeration value.
    /// @return true if a constant in enumType has a value equal to value; otherwise, false.
    /// @exception xtd::argument_exception The value is ! a value of enumType.
    template<typename enum_t>
    static bool is_defined(enum_t value) noexcept {return std::find_if(enum_object<enum_t>().entries().begin(), enum_object<enum_t>().entries().end(), [&](auto item)->bool {return item.first == value;}) != enum_object<enum_t>().entries().end();}
    /// @brief Returns an indication whether a constant with a specified value exists in a specified enumeration.
    /// @param fromValue An enumeration value.
    /// @return true if a constant in enumType has a value equal to value; otherwise, false.
    /// @exception xtd::argument_exception The value is ! a value of enumType.
    template<typename enum_t>
    static bool is_defined(enum_object<enum_t> value) noexcept {return std::find_if(enum_object<enum_t>().entries().begin(), enum_object<enum_t>().entries().end(), [&](auto item)->bool {return item.first == value;}) != enum_object<enum_t>().entries().end();}
    
    /// @brief Converts the xtd::ustring representation of the name or numeric value of one or more enumerated constants to an equivalent enumerated object.
    /// @param value An A xtd::ustring containing the name or value to convert.
    /// @return enum_object An enum whose value is represented by value.
    /// @exception xtd::argument_exception The value is ! a value of enumType.
    template<typename enum_t>
    static enum_t parse(const xtd::ustring& value) noexcept {return parse<enum_t>(value, false);}
    /// @brief Converts the xtd::ustring representation of the name or numeric value of one or more enumerated constants to an equivalent enumerated object.
    /// @param str An A xtd::ustring containing the name or value to convert.
    /// @param ignore_case true to Ignore case; false to regard case.
    /// @return enum_object An enum whose value is represented by value.
    /// @exception xtd::argument_exception The value is ! a value of enumType.
    template<typename enum_t>
    static enum_t parse(const xtd::ustring& str, bool ignore_case) {
      return enum_object<enum_t>::parse(str, ignore_case);
    }
    
    /// @brief Converts this instance to byte.
    /// @return A new xtd::byte object converted from this instance.
    /// @param value The value to convert.
    template<typename enum_t>
    static xtd::byte to_byte(enum_t value) noexcept {return enum_object<enum_t>(value).to_byte();}
    
    /// @brief Converts this instance to int16.
    /// @param value The value to convert.
    /// @return A new to_int16 object converted from this instance.
    template<typename enum_t>
    static int16 to_int16(enum_t value) noexcept {return enum_object<enum_t>(value).to_int16();}
    
    /// @brief Converts this instance to int32.
    /// @param value The value to convert.
    /// @return A new to_int32 object converted from this instance.
    template<typename enum_t>
    static int32 to_int32(enum_t value) noexcept {return enum_object<enum_t>(value).to_int32();}
    
    /// @brief Converts this instance to int64.
    /// @param value The value to convert.
    /// @return A new to_int64 object converted from this instance.
    template<typename enum_t>
    static int64 to_int64(enum_t value) noexcept {return enum_object<enum_t>(value).to_int64();}
    
    /// @brief Converts this instance to signed byte.
    /// @param value The value to convert.
    /// @return A new sbyte object converted from this instance.
    template<typename enum_t>
    static sbyte to_sbyte(enum_t value) noexcept {return enum_object<enum_t>(value).to_sbyte();}
    
    /// @brief Converts this instance to unsigned int16.
    /// @param value The value to convert.
    /// @return A new to_uint16 object converted from this instance.
    template<typename enum_t>
    static uint16 to_uint16(enum_t value) noexcept {return enum_object<enum_t>(value).to_uint16();}
    
    /// @brief Converts this instance to unsigned int32.
    /// @param value The value to convert.
    /// @return A new to_uint32 object converted from this instance.
    template<typename enum_t>
    static uint32 to_uint32(enum_t value) noexcept {return enum_object<enum_t>(value).to_uint32();}
    
    /// @brief Converts this instance to unsigned int64.
    /// @param value The value to convert.
    /// @return A new to_uint64 object converted from this instance.
    template<typename enum_t>
    static uint64 to_uint64(enum_t value) noexcept {return enum_object<enum_t>(value).to_uint64();}
    
    /// @brief Converts the xtd::ustring representation of the name or numeric value of one or more enumerated constants to an equivalent enumerated object. The return value indicates whether the conversion succeeded.
    /// @param vaue The xtd::ustring representation of the enumeration name or underlying value to convert.
    /// @param reslt When this method returns, result contains an object of type TEnum whose value is represented by value if the parse operation succeeds. If the parse operation fails, result contains the default value of the underlying type of TEnum. Note that this value need ! be a member of the TEnum enumeration. This parameter is passed uninitialized.
    /// @return true if the value parameter was converted successfully; otherwise, false.
    template<typename enum_t>
    static bool try_parse(const xtd::ustring& value, enum_t& result) noexcept {return try_parse<enum_t>(value, false, result);}
    
    /// @brief Converts the xtd::ustring representation of the name or numeric value of one or more enumerated constants to an equivalent enumerated object. A parameter specifies whether the operation is case-sensitive. The return value indicates whether the conversion succeeded.
    /// @param vaue The xtd::ustring representation of the enumeration name or underlying value to convert.
    /// @param ignore_case true to Ignore case; false to regard case.
    /// @param reslt When this method returns, result contains an object of type TEnum whose value is represented by value if the parse operation succeeds. If the parse operation fails, result contains the default value of the underlying type of TEnum. Note that this value need ! be a member of the TEnum enumeration. This parameter is passed uninitialized.
    /// @return true if the value parameter was converted successfully; otherwise, false.
    template<typename enum_t>
    static bool try_parse(const xtd::ustring& value, bool ignore_case, enum_t& result) noexcept {
      try {
        result = parse<enum_t>(value, ignore_case);
        return true;
      } catch (...) {
        return false;
      }
    }
  };
  
  /// @cond
  template<typename type_t>
  inline std::string to_string(const xtd::enum_object<type_t>& value, const std::string& fmt, const std::locale& loc) {
    return value.to_string(fmt);
  }
  /// @endcond
}

#define flags_attribute_(namespace_name, enum_type) \
  namespace namespace_name { \
    [[maybe_unused]] inline enum_type& operator ^=(enum_type& lhs, enum_type rhs) {lhs = static_cast<enum_type>(static_cast<std::underlying_type<enum_type>::type>(lhs) ^ static_cast<std::underlying_type<enum_type>::type>(rhs)); return lhs;} \
    [[maybe_unused]] inline enum_type& operator &=(enum_type& lhs, enum_type rhs) {lhs = static_cast<enum_type>(static_cast<std::underlying_type<enum_type>::type>(lhs) & static_cast<std::underlying_type<enum_type>::type>(rhs)); return lhs;} \
    [[maybe_unused]] inline enum_type& operator |=(enum_type& lhs, enum_type rhs) {lhs = static_cast<enum_type>(static_cast<std::underlying_type<enum_type>::type>(lhs) | static_cast<std::underlying_type<enum_type>::type>(rhs)); return lhs;} \
    [[maybe_unused]] inline enum_type& operator +=(enum_type& lhs, enum_type rhs) {lhs = static_cast<enum_type>(static_cast<std::underlying_type<enum_type>::type>(lhs) + static_cast<std::underlying_type<enum_type>::type>(rhs)); return lhs;} \
    [[maybe_unused]] inline enum_type& operator -=(enum_type& lhs, enum_type rhs) {lhs = static_cast<enum_type>(static_cast<std::underlying_type<enum_type>::type>(lhs) - static_cast<std::underlying_type<enum_type>::type>(rhs)); return lhs;} \
    [[maybe_unused]] inline enum_type operator ^(enum_type lhs, enum_type rhs) {return static_cast<enum_type>(static_cast<std::underlying_type<enum_type>::type>(lhs) ^ static_cast<std::underlying_type<enum_type>::type>(rhs));} \
    [[maybe_unused]] inline enum_type operator &(enum_type lhs, enum_type rhs) {return static_cast<enum_type>(static_cast<std::underlying_type<enum_type>::type>(lhs) & static_cast<std::underlying_type<enum_type>::type>(rhs));} \
    [[maybe_unused]] inline enum_type operator |(enum_type lhs, enum_type rhs) {return static_cast<enum_type>(static_cast<std::underlying_type<enum_type>::type>(lhs) | static_cast<std::underlying_type<enum_type>::type>(rhs));} \
    [[maybe_unused]] inline enum_type operator +(enum_type lhs, enum_type rhs) {return static_cast<enum_type>(static_cast<std::underlying_type<enum_type>::type>(lhs) + static_cast<std::underlying_type<enum_type>::type>(rhs));} \
    [[maybe_unused]] inline enum_type operator -(enum_type lhs, enum_type rhs) {return static_cast<enum_type>(static_cast<std::underlying_type<enum_type>::type>(lhs) - static_cast<std::underlying_type<enum_type>::type>(rhs));} \
    [[maybe_unused]] inline enum_type operator ~(enum_type lhs) {return static_cast<enum_type>(~static_cast<std::underlying_type<enum_type>::type>(lhs));} \
  }\
  template<> struct xtd::enum_set_attribute<namespace_name::enum_type> { \
    explicit operator auto() const noexcept {return xtd::enum_attribute::flags;} \
  }

#define enum_ut_(namespace_name, enum_type, underlying_type, ...) \
  namespace namespace_name { enum enum_type : underlying_type {__VA_ARGS__}; } \
  template<> struct xtd::enum_register<namespace_name::enum_type> { \
    explicit operator auto() const {return __enum_definition_to_enum_collection__<namespace_name::enum_type>(#__VA_ARGS__);} \
  }

#define enum_class_ut_(namespace_name, enum_class_type, underlying_type, ...) \
  namespace namespace_name { enum class enum_class_type : underlying_type { __VA_ARGS__ }; } \
  template<> struct xtd::enum_register<namespace_name::enum_class_type> { \
    explicit operator auto() const {return __enum_definition_to_enum_collection__<namespace_name::enum_class_type>(#__VA_ARGS__);} \
  }

#define enum_struct_ut_(namespace_name, enum_struct_type, underlying_type, ...) \
  namespace namespace_name { enum struct enum_struct_type : underlying_type { __VA_ARGS__ }; } \
  template<> struct xtd::enum_register<namespace_name::enum_struct_type> { \
    explicit operator auto() const {return __enum_definition_to_enum_collection__<namespace_name::enum_struct_type>(#__VA_ARGS__);} \
  }

#define enum_(namespace_name, enum_type, ...) \
  enum_ut_(namespace_name, enum_type, int32, __VA_ARGS__)

#define enum_class_(namespace_name, enum_class_type, ...) \
  enum_class_ut_(namespace_name, enum_class_type, int32, __VA_ARGS__)

#define enum_struct_(namespace_name, enum_struct_type, ...) \
  enum_struct_ut_(namespace_name, enum_struct_type, int32, __VA_ARGS__)

/// @cond
template<typename enum_t>
inline std::string __enum_to_string(enum_t value) noexcept {
  return xtd::enum_object<>::get_name(value);
}

template<> struct xtd::enum_register<xtd::enum_attribute> {
  explicit operator auto() const noexcept {return xtd::enum_collection<xtd::enum_attribute> {{enum_attribute::standard, L"standard"}, {enum_attribute::flags, L"flags"}};}
};

template<> struct xtd::enum_set_attribute<xtd::number_styles> {
  explicit operator auto() const noexcept {return xtd::enum_attribute::flags;}
};

template<> struct xtd::enum_register<xtd::number_styles> {
  explicit operator auto() const noexcept {return xtd::enum_collection<xtd::number_styles> {{xtd::number_styles::none, "none"}, {xtd::number_styles::allow_leading_white, "allow_leading_white"}, {xtd::number_styles::allow_trailing_white, "allow_trailing_white"}, {xtd::number_styles::allow_leading_sign, "allow_leading_sign"}, {xtd::number_styles::allow_trailing_sign, "allow_trailing_sign"}, {xtd::number_styles::allow_parentheses, "allow_parentheses"}, {xtd::number_styles::allow_decimal_point, "allow_decimal_point"}, {xtd::number_styles::allow_thousands, "allow_thousands"}, {xtd::number_styles::allow_exponent, "allow_exponent"}, {xtd::number_styles::allow_currency_symbol, "allow_currency_symbol"}, {xtd::number_styles::allow_hex_specifier, "allow_hex_specifier"}, {xtd::number_styles::allow_binary_specifier, "allow_binary_specifier"}, {xtd::number_styles::allow_octal_specifier, "allow_octal_specifier"}, {xtd::number_styles::integer, "integer"}, {xtd::number_styles::number, "number"}, {xtd::number_styles::fixed_point, "fixed_point"}, {xtd::number_styles::currency, "currency"}, {xtd::number_styles::any, "any"}, {xtd::number_styles::hex_number, "hex_number"}, {xtd::number_styles::binary_number, "binary_number"}, {xtd::number_styles::octal_number, "octal_number"}};}
};

template<> struct xtd::enum_register<xtd::string_comparison> {
  explicit operator auto() const noexcept {return xtd::enum_collection<xtd::string_comparison> {{xtd::string_comparison::ordinal, "ordinal"}, {xtd::string_comparison::ordinal_ignore_case, "ordinal_ignore_case"}};}
};

template<> struct xtd::enum_register<xtd::string_split_options> {
  explicit operator auto() const noexcept {return xtd::enum_collection<xtd::string_split_options> {{xtd::string_split_options::none, "none"}, {xtd::string_split_options::remove_empty_entries, "remove_empty_entries"}};}
};
/// @endcond
