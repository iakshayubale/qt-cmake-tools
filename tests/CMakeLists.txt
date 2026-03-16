# Test suite for qt-cmake-tools
# These tests verify that the CMake modules work correctly

cmake_minimum_required(VERSION 3.16)
project(qt-cmake-tools-tests)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_AUTOMOC ON)

# Add qt-cmake-tools modules
list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/../cmake")

enable_testing()

# Test 1: Module Loading
message(STATUS "Testing: Module Loading")
include(QtAutoDeploy)
include(QtAutoQmlModule)
include(QtSetupProject)
include(QtUtils)
message(STATUS "✓ All modules loaded successfully")

# Test 2: Qt Discovery
message(STATUS "Testing: Qt Discovery")
find_package(Qt6 COMPONENTS Core Gui REQUIRED)
if(Qt6_FOUND)
    message(STATUS "✓ Qt6 found: ${Qt6_VERSION}")
endif()

# Test 3: Configuration Summary
message(STATUS "Testing: Configuration Summary")
qt_print_config()
message(STATUS "✓ Configuration printed successfully")

# Create a simple test executable
message(STATUS "Testing: Test Executable Creation")
set(TEST_SOURCES
    test_cmake_modules.cpp
)

add_executable(test_cmake_modules ${TEST_SOURCES})
target_link_libraries(test_cmake_modules PRIVATE Qt6::Core Qt6::Test)

add_test(NAME CMakeModulesTest COMMAND test_cmake_modules)
message(STATUS "✓ Test executable created")

message(STATUS "")
message(STATUS "All tests configured successfully!")
message(STATUS "Run tests with: ctest --output-on-failure")
message(STATUS "")
