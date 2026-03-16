# Qt CMake Tools - Testing Guide

## Running Tests

### Build and Run All Tests

```bash
cd build
cmake .. -DBUILD_TESTING=ON
cmake --build .
ctest --output-on-failure
```

### Run Specific Test

```bash
ctest -R CMakeModulesTest --output-on-failure
```

### Verbose Output

```bash
ctest --output-on-failure -V
```

---

## Test Coverage

### 1. **CMake Module Loading**
   - ✓ All CMake modules can be included without errors
   - ✓ Functions are properly defined

### 2. **Qt Discovery**
   - ✓ Qt6 is properly discovered
   - ✓ Qt components are available

### 3. **Configuration**
   - ✓ Qt version is correctly reported
   - ✓ CMake configuration functions work

### 4. **Unit Tests**
   - ✓ Qt signals and slots work correctly
   - ✓ String handling functions work
   - ✓ Qt version macro is accessible

---

## Adding New Tests

To add a new test:

1. Create a new `.cpp` file in `tests/`
2. Include it in `CMakeLists.txt`:
   ```cmake
   add_executable(my_test my_test.cpp)
   target_link_libraries(my_test PRIVATE Qt6::Test Qt6::Core)
   add_test(NAME MyTest COMMAND my_test)
   ```
3. Run: `ctest --output-on-failure`

---

## Test Results

Expected output:
```
Pass   : QtCMakeToolsTest::test_qt_version
Pass   : QtCMakeToolsTest::test_cmake_modules_available
Pass   : QtCMakeToolsTest::test_core_functionality
Pass   : QtCMakeToolsTest::test_signal_slot

Total: 4 pass, 0 fail
```

---

## Continuous Integration

Tests are designed to run in CI/CD pipelines. Key points:

- No platform-specific hardcoding
- Tests are self-contained
- Expected to pass on Windows, macOS, and Linux
- Requires Qt6 installation

