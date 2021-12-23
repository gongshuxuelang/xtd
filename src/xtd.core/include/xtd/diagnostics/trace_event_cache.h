/// @file
/// @brief Contains xtd::diagnostics::trace_event_cache class.
/// @copyright Copyright (c) 2021 Gammasoft. All rights reserved.
#pragma once
#include <chrono>
#include <string>
#include <thread>
#include <vector>
#include "../object.h"
#include "../ustring.h"

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::diagnostics namespace provides classes that allow you to interact with system processes, event logs, and performance counters.
  namespace diagnostics {
    /// @brief Provides trace event data specific to a thread and a process.
    /// @code
    /// class core_export_ trace_event_cache : public xtd::object
    /// @endcode
    /// @par Inheritance
    /// xtd::object → xtd::diagnostics::trace_event_cache
    /// @par Namespace
    /// xtd::diagnostics
    /// @par Library
    /// xtd.core
    /// @ingroup xtd_core
    class core_export_ trace_event_cache : public xtd::object {
    public:
      /// @name Alias
      
      /// @{
      //using clock = std::chrono::high_resolution_clock;
      using clock = std::chrono::system_clock;
      /// @}

      /// @name Constructors
      
      /// @{
      /// @brief Initializes a new instance of the trace_event_cache class.
      trace_event_cache() = default;
      /// @}
      
      /// @cond
      trace_event_cache(const trace_event_cache& tec);
      trace_event_cache& operator=(const trace_event_cache& tec) = default;
      /// @endcond
      
      /// @name Properties
      
      /// @{
      /// @brief Gets the call stack for the current thread.
      /// @return string A string containing stack trace information. This value can be an empty string ("").
      /// @remarks The Callstack property gets the call stack from the StackTrace property of the Environment class. The property value lists method calls in reverse chronological order. That is, the most recent method call is described first. One line of stack trace information is listed for each method call on the stack. For more information, see StackTrace.
      xtd::ustring call_stack() const;
      
      /// @brief Gets the date and time at which the event trace occurred.
      /// @return DateTime A DateTime structure whose value is a date and time expressed in Coordinated Universal Time (UTC).
      /// @remarks The first time the property is accessed in an instance of the trace_event_cache class, the current time is returned. Subsequent queries of this property in that instance return that same DateTime value, allowing it to be used as a timestamp.
      clock::time_point date_time() const;
      
      /// @brief Gets the correlation data, contained in a stack.
      /// @return A Stack containing correlation data.
      /// @remarks The correlation data is stored as an object in the call context with the name "System.Diagnostics.Trace.CorrelationManagerSlot". The CorrelationManager class provides methods used to store a logical operation identity in a thread-bound context and automatically tag each trace event generated by the thread with the stored identity. The CorrelationManager is accessed through the Trace.CorrelationManager property. Each call to the StartLogicalOperation method pushes a new logical operation identity onto the stack. Each call to the StopLogicalOperation method pops a logical operation identity from the stack
      std::vector<xtd::ustring> logical_operation_stack() const;
      
      /// @brief Gets the unique identifier of the current process.
      /// @return int32 The system-generated unique identifier of the current process.
      /// @remarks Until the process terminates, the process identifier uniquely identifies the process throughout the system.
      int32_t process_id() const;
      
      /// @brief Gets a unique identifier for the current managed thread.
      /// @return string A string that represents a unique integer identifier for this managed thread.
      /// @remarks The thread identifier is the value of the Thread.ManagedThreadId property formatted as a string.
      xtd::ustring thread_id() const;
      
      /// @brief Gets the current number of ticks in the timer mechanism.
      /// @return int64 The tick counter value of the underlying timer mechanism.
      /// @remarks The get accessor calls the Stopwatch.GetTimestamp method to get the timestamp. If the Stopwatch class uses a high-resolution performance counter, GetTimestamp returns the current value of that counter. If the Stopwatch class uses the system timer, GetTimestamp returns the Ticks property of DateTime.Now.
      int64_t timestamp() const;
      /// @}
    
    private:
      mutable clock::time_point date_time_ = clock::time_point::min();
    };
  }
}
