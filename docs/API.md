# Qt CMake Tools - API Documentation

## Overview

Qt CMake Tools provides a comprehensive set of CMake utilities to simplify Qt application development. These tools handle common tasks like deployment, QML module discovery, and project scaffolding.

---

## Table of Contents

1. [QtAutoDeploy Module](#qtautodeploy-module)
2. [QtAutoQmlModule Module](#qtautoqmlmodule-module)
3. [QtSetupProject Module](#qtsetupproject-module)
4. [QtUtils Module](#qtutils-module)

---

## QtAutoDeploy Module

### Purpose

Automatically configures Qt application deployment, including:
- Plugin discovery and bundling
- Runtime path (RPATH) configuration for Unix-like systems
- Cross-platform deployment setup

### Functions

#### `qt_auto_deploy()`

Configures automatic deployment for a Qt application.

**Parameters:**
- `TARGET` (required): The executable target to deploy
- `DEPLOY_DIR` (optional): Directory where deployment files are copied (default: `${CMAKE_BINARY_DIR}/deploy`)

**Example:**
```cmake
add_executable(myapp src/main.cpp)
target_link_libraries(myapp PRIVATE Qt6::Core Qt6::Gui)

qt_auto_deploy(TARGET myapp)
```

**What it does:**
1. Detects Qt version (5 or 6)
2. Locates Qt plugin directory
3. Copies all Qt plugins to deployment directory
4. Configures RPATH for Unix systems (Linux/macOS)
5. Sets up proper installation targets

---

## QtAutoQmlModule Module

### Purpose

Automatically discovers and registers QML files, eliminating manual file listing in CMakeLists.txt.

### Functions

#### `qt_auto_qml_module()`

Automatically discovers and configures QML modules.

**Parameters:**
- `TARGET` (required): The executable target
- `URI` (required): QML module URI (e.g., `MyApp.Module`)
- `QML_DIR` (optional): Path to QML files directory (default: `${CMAKE_CURRENT_SOURCE_DIR}/qml`)
- `VERSION` (optional): Module version (default: `1.0`)

**Example:**
```cmake
qt_auto_qml_module(
    TARGET myqmlapp
    URI MyApp
    QML_DIR "${CMAKE_CURRENT_SOURCE_DIR}/qml"
    VERSION "1.0"
)
```

**What it does:**
1. Scans QML directory recursively
2. Discovers all `.qml` and `.js` files
3. Creates `qmldir` file if missing
4. Registers QML module with Qt6
5. Automatically includes all discovered files

#### `qt_list_qml_files()`

Helper function to list all QML files in a directory.

**Parameters:**
- `QML_DIR`: Directory to search
- `OUT_VAR`: Output variable name

**Example:**
```cmake
qt_list_qml_files("${CMAKE_CURRENT_SOURCE_DIR}/qml" QML_FILES)
message(STATUS "Found QML files: ${QML_FILES}")
```

---

## QtSetupProject Module

### Purpose

Quickly scaffold new Qt projects with best-practice directory structure.

### Functions

#### `qt_setup_project()`

Creates a new Qt project with recommended structure.

**Parameters:**
- `PROJECT_NAME` (required): Name of the project
- `TYPE` (optional): Project type - `console`, `widget`, or `qml` (default: `console`)

**Example:**
```cmake
qt_setup_project(myapp TYPE widget)
qt_setup_project(myqmlapp TYPE qml)
```

**What it creates:**
```
myapp/
├── src/
│   └── main.cpp
├── cmake/
├── tests/
├── CMakeLists.txt
└── .gitignore
```

For QML projects, additionally creates:
```
└── qml/
    └── main.qml
└── assets/
```

---

## QtUtils Module

### Purpose

Provide general-purpose utility functions for Qt projects.

### Functions

#### `qt_print_config()`

Print Qt configuration summary.

**Example:**
```cmake
qt_print_config()
```

**Output:**
```
========== Qt Configuration ==========
Qt Version:        Qt 6.x (6.5.0)
CMake Version:     3.27.0
C++ Standard:      17
Build Type:        Release
========================================
```

#### `qt_enable_strict_warnings()`

Enable strict compiler warnings.

**Parameters:**
- `TARGET` (required): Target to apply warnings to

**Example:**
```cmake
qt_enable_strict_warnings(myapp)
```

#### `qt_add_test()`

Add a Qt test executable.

**Parameters:**
- `TEST_NAME`: Name of the test
- `TEST_SOURCE`: Source file(s)

**Example:**
```cmake
qt_add_test(my_tests tests/tst_mytest.cpp)
```

#### `qt_get_install_dir()`

Get Qt installation directory.

**Parameters:**
- `OUT_VAR`: Output variable name

**Example:**
```cmake
qt_get_install_dir(QT_DIR)
message(STATUS "Qt installed at: ${QT_DIR}")
```

#### `qt_configure_platform()`

Apply platform-specific configuration.

**Parameters:**
- `TARGET` (required): Target to configure

**Example:**
```cmake
qt_configure_platform(myapp)
```

#### `qt_create_bundle()`

Create platform-specific application bundle (macOS .app, Windows executable).

**Parameters:**
- `TARGET` (required): Target to bundle

**Example:**
```cmake
qt_create_bundle(myapp)
```

---

## Complete Example

Here's a complete CMakeLists.txt using Qt CMake Tools:

```cmake
cmake_minimum_required(VERSION 3.16)
project(MyAwesomeApp)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

# Add qt-cmake-tools to module path
list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/../cmake")

# Include our utilities
include(QtAutoDeploy)
include(QtAutoQmlModule)
include(QtUtils)

find_package(Qt6 COMPONENTS Core Gui Qml Quick REQUIRED)

# Main application
set(SOURCES
    src/main.cpp
    src/app.cpp
    src/app.h
)

set(QML_FILES
    qml/main.qml
    qml/components/Button.qml
)

add_executable(MyAwesomeApp ${SOURCES})

# Setup QML module
qt_auto_qml_module(
    TARGET MyAwesomeApp
    URI MyAwesomeApp
    QML_DIR "${CMAKE_CURRENT_SOURCE_DIR}/qml"
)

target_link_libraries(MyAwesomeApp PRIVATE
    Qt6::Core
    Qt6::Gui
    Qt6::Qml
    Qt6::Quick
)

# Configure deployment
qt_auto_deploy(TARGET MyAwesomeApp)

# Enable warnings
qt_enable_strict_warnings(MyAwesomeApp)

# Platform configuration
qt_configure_platform(MyAwesomeApp)
qt_create_bundle(MyAwesomeApp)

# Print configuration
qt_print_config()
```

---

## Best Practices

1. **Always use `qt_auto_deploy()`** - Ensures plugins are properly bundled and paths are correct
2. **Use `qt_auto_qml_module()`** - Eliminates manual file listing and is less error-prone
3. **Include module paths** - Add cmake directory to CMAKE_MODULE_PATH
4. **Enable strict warnings** - Catch errors early with `qt_enable_strict_warnings()`
5. **Test on all platforms** - Use `qt_configure_platform()` to handle platform differences

---

## Troubleshooting

### Issue: "Qt not found" error

**Solution:** Make sure to call `find_package(Qt6 COMPONENTS ...)` BEFORE including qt-cmake-tools modules.

### Issue: Plugins not found at runtime

**Solution:** Use `qt_auto_deploy()` to automatically configure paths and bundle plugins.

### Issue: QML files not found

**Solution:** Ensure QML_DIR points to the correct directory. Use absolute path or relative to CMAKE_CURRENT_SOURCE_DIR.

