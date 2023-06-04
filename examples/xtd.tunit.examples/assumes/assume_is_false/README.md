# assert_is_false

Shows how to use [xtd::tunit::assert::is_false](https://gammasoft71.github.io/xtd/reference_guides/latest/classxtd_1_1tunit_1_1assume.html#a7a8a9392f55aaa14fc7d01cba25718ff) method.

## Sources

[src/assert_is_false.cpp](src/assert_is_false.cpp)

[CMakeLists.txt](CMakeLists.txt)

# Build and run

Open "Command Prompt" or "Terminal". Navigate to the folder that contains the project and type the following:

```cmake
xtdc run
```

# Output

```
Start 2 tests from 1 test case
Run tests:
  SUCCEED test.test_case_succeed (0 ms total)
  ABORTED test.test_case_failed (0 ms total)
    Expected: false
    But was:  true
    Stack Trace: in |---OMITTED---|/assert_is_false.cpp:16

Test results:
  SUCCEED 1 test.
  ABORTED 1 test.
End 2 tests from 1 test case ran. (0 ms total)
```