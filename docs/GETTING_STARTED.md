# Getting Started with Qt CMake Tools

## Installation

### Option 1: Copy to Your Project

1. Copy the `cmake/` folder to your project
2. Add to your CMakeLists.txt:

```cmake
list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/cmake")
include(QtAutoDeploy)
include(QtAutoQmlModule)
```

### Option 2: Install to System

```bash
mkdir build && cd build
cmake ..
cmake --install .
```

Then use in your projects:

```cmake
find_package(qt-cmake-tools REQUIRED)
```

---

## Quick Start: Building Your First App

### 1. Console Application

```cmake
cmake_minimum_required(VERSION 3.16)
project(HelloConsole)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_AUTOMOC ON)

# Add qt-cmake-tools path
list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/../qt-cmake-tools/cmake")

find_package(Qt6 COMPONENTS Core REQUIRED)

add_executable(hello src/main.cpp)
target_link_libraries(hello PRIVATE Qt6::Core)
```

### 2. GUI Widget Application

```cmake
cmake_minimum_required(VERSION 3.16)
project(HelloWidget)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/../qt-cmake-tools/cmake")

find_package(Qt6 COMPONENTS Core Gui Widgets REQUIRED)

add_executable(hello 
    src/main.cpp
    src/mainwindow.cpp
    src/mainwindow.h
)

target_link_libraries(hello PRIVATE Qt6::Core Qt6::Gui Qt6::Widgets)
```

### 3. QML Application with Automatic Deployment

```cmake
cmake_minimum_required(VERSION 3.16)
project(HelloQML)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/../qt-cmake-tools/cmake")
include(QtAutoDeploy)
include(QtAutoQmlModule)

find_package(Qt6 COMPONENTS Core Gui Qml Quick REQUIRED)

add_executable(hello src/main.cpp)

# Automatically discover and register QML files
qt_auto_qml_module(
    TARGET hello
    URI HelloQML
    QML_DIR "${CMAKE_CURRENT_SOURCE_DIR}/qml"
)

target_link_libraries(hello PRIVATE Qt6::Core Qt6::Gui Qt6::Qml Qt6::Quick)

# Automatically handle deployment
qt_auto_deploy(TARGET hello)
```

---

## Building Projects

### Using CMake directly

```bash
# Windows (MSVC)
cmake -B build -G "Visual Studio 16 2019" -DCMAKE_PREFIX_PATH=C:/Qt/6.5.0/msvc2019_64
cmake --build build --config Release

# Linux (Unix Makefiles)
cmake -B build -DCMAKE_PREFIX_PATH=/opt/Qt/6.5.0/gcc_64
cmake --build build --config Release

# macOS (Xcode)
cmake -B build -G Xcode -DCMAKE_PREFIX_PATH=/Users/username/Qt/6.5.0/macos
cmake --build build --config Release
```

### Running Tests

```bash
cd build
ctest --output-on-failure
```

---

## Using Qt CMake Tools in Your Projects

### Step 1: Include the Modules

```cmake
list(APPEND CMAKE_MODULE_PATH "${PATH_TO_QT_CMAKE_TOOLS}/cmake")

include(QtAutoDeploy)
include(QtAutoQmlModule)
include(QtSetupProject)
include(QtUtils)
```

### Step 2: Use the Functions

```cmake
# Print configuration
qt_print_config()

# Configure QML module
qt_auto_qml_module(
    TARGET myapp
    URI MyApp
)

# Prepare for deployment
qt_auto_deploy(TARGET myapp)

# Enable strict warnings
qt_enable_strict_warnings(myapp)
```

### Step 3: Build and Deploy

```bash
cmake -B build -DCMAKE_PREFIX_PATH=/path/to/Qt/installation
cmake --build build --config Release
cmake --install build --prefix ./deploy
```

---

## Frequently Asked Questions

**Q: Do I need to use all functions?**  
A: No! Use only what you need. It's perfectly fine to use just `qt_auto_deploy()` if that's all your project requires.

**Q: Can I use this with Qt 5?**  
A: Most features work with Qt 5, with reduced functionality for QML auto-discovery (which is a Qt 6 feature).

**Q: How do I distribute my application?**  
A: Use `qt_auto_deploy()` to prepare the deployment directory, then package it for your platform.

**Q: Can I customize deployment directories?**  
A: Yes! Use `qt_auto_deploy(TARGET myapp DEPLOY_DIR /custom/path)`.

