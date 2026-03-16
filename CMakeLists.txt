cmake_minimum_required(VERSION 3.16)
project(qt-cmake-tools)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

# Project version
set(QT_CMAKE_TOOLS_VERSION_MAJOR 1)
set(QT_CMAKE_TOOLS_VERSION_MINOR 0)
set(QT_CMAKE_TOOLS_VERSION_PATCH 0)
set(QT_CMAKE_TOOLS_VERSION ${QT_CMAKE_TOOLS_VERSION_MAJOR}.${QT_CMAKE_TOOLS_VERSION_MINOR}.${QT_CMAKE_TOOLS_VERSION_PATCH})

# Find Qt6
find_package(Qt6 COMPONENTS Core Gui Widgets Qml Quick REQUIRED)

# Include our CMake modules
list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/cmake")

# Enable testing
enable_testing()

# Add subdirectories
add_subdirectory(cmake)
add_subdirectory(examples)
if(BUILD_TESTING)
    add_subdirectory(tests)
endif()

# Display configuration summary
message(STATUS "")
message(STATUS "Qt CMake Tools v${QT_CMAKE_TOOLS_VERSION}")
message(STATUS "========================================")
message(STATUS "Build Type:          ${CMAKE_BUILD_TYPE}")
message(STATUS "Qt Version:          ${Qt6_VERSION}")
message(STATUS "C++ Standard:        ${CMAKE_CXX_STANDARD}")
message(STATUS "Testing Enabled:     ${BUILD_TESTING}")
message(STATUS "========================================")
message(STATUS "")
