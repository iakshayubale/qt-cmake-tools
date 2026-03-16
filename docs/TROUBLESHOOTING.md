# Troubleshooting Guide

## Common Issues and Solutions

### Building & Compilation

#### ❌ Error: "Qt not found"

**Symptom:**
```
CMake Error: Could not find Qt components
```

**Cause:** CMake can't locate your Qt installation.

**Solution:**
1. Windows:
   ```bash
   cmake -DCMAKE_PREFIX_PATH=C:/Qt/6.5.0/msvc2019_64 ..
   ```

2. Linux:
   ```bash
   cmake -DCMAKE_PREFIX_PATH=/opt/Qt/6.5.0/gcc_64 ..
   ```

3. macOS:
   ```bash
   cmake -DCMAKE_PREFIX_PATH=$HOME/Qt/6.5.0/macos ..
   ```

Or set environment variable permanently:
```bash
# Linux/macOS
export Qt6_DIR=/path/to/Qt/6.5.0/lib/cmake/Qt6

# Windows (PowerShell)
$env:Qt6_DIR = "C:\Qt\6.5.0\msvc2019_64\lib\cmake\Qt6"
```

---

#### ❌ Error: "Cannot find module: ...cmake"

**Symptom:**
```
CMake Error: include could not find load file: QtAutoDeploy.cmake
```

**Cause:** CMake module path not set correctly.

**Solution:**
Make sure your `CMakeLists.txt` has:
```cmake
list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/cmake")
include(QtAutoDeploy)
```

Or use absolute path:
```cmake
list(APPEND CMAKE_MODULE_PATH "/absolute/path/to/qt-cmake-tools/cmake")
```

---

#### ❌ Error: "Unresolved external symbol" (Linking error)

**Symptom:**
```
error LNK2001: unresolved external symbol "Qt::Core"
```

**Cause:** Not linking Qt libraries properly.

**Solution:**
```cmake
find_package(Qt6 COMPONENTS Core Gui Widgets REQUIRED)
# ... create your target ...
target_link_libraries(myapp PRIVATE Qt6::Core Qt6::Gui Qt6::Widgets)
```

Make sure all Qt components you use are both:
1. In `find_package()` 
2. In `target_link_libraries()`

---

### Runtime Issues

#### ❌ Error: App crashes on startup with "MSVCP140.dll not found"

**Symptom:**
Your exe runs fine on your dev machine but crashes on another machine.

**Cause:** Missing Visual C++ runtime dependencies.

**Solution:**
1. Use `qt_auto_deploy()` to bundle dependencies:
   ```cmake
   qt_auto_deploy(TARGET myapp)
   ```

2. Or manually include Visual C++ runtime:
   - Download VCRedist from Microsoft
   - Include in your installer

---

#### ❌ App runs but shows: "Could not find the Qt platform plugin"

**Symptom:**
```
This application failed to start because it could not find or load the Qt platform plugin...
```

**Cause:** Qt platform plugin (Windows, XCB, macOS, etc.) is missing.

**Solution:**
1. **Best Option**: Use `qt_auto_deploy()`:
   ```cmake
   qt_auto_deploy(TARGET myapp)
   ```

2. **Manual Fix**: Copy plugin directory:
   - Windows: Copy `plugins/platforms/qwindows.dll`  
   - Linux: Copy `plugins/platforms/libqxcb.so`
   - macOS: Copy `plugins/platforms/libqcocoa.dylib`

3. **Manual Path Setting**: Export QT_PLUGIN_PATH:
   ```bash
   # Linux/macOS
   export QT_PLUGIN_PATH=/path/to/Qt/plugins
   ./myapp
   
   # Windows (PowerShell)
   $env:QT_PLUGIN_PATH = "C:\Qt\6.5.0\msvc2019_64\plugins"
   .\myapp.exe
   ```

---

#### ❌ QML module not found at runtime

**Symptom:**
```
QML module not found
import statements failed to import
```

**Cause:** QML files not properly registered or qmldir file missing.

**Solution:**
1. Use `qt_auto_qml_module()`:
   ```cmake
   qt_auto_qml_module(
       TARGET myapp
       URI MyApp
       QML_DIR "${CMAKE_CURRENT_SOURCE_DIR}/qml"
   )
   ```

2. Manually check:
   - All `.qml` files are in the correct directory
   - `qmldir` file exists in QML directory
   - `qmldir` format is correct:
     ```
     module MyApp
     main.qml
     Button.qml
     ```

---

#### ❌ Application loads wrong QML file

**Symptom:**
Your app loads but displays wrong content or fails to find specific QML.

**Cause:** Incorrect QML path in source code or resource path.

**Solution:**
```cpp
// Correct ways to load QML:

// Option 1: Using qrc:// (resource path)
engine.load(QUrl(QStringLiteral("qrc:/qml/main.qml")));

// Option 2: Using relative path
engine.load(QUrl::fromLocalFile(QStringLiteral("qml/main.qml")));

// Option 3: Using absolute path (for development only)
engine.load(QUrl::fromLocalFile(
    QStringLiteral(CMAKE_SOURCE_DIR "/qml/main.qml")));
```

---

### CMake-Specific Issues

#### ❌ Error: "AUTOMOC" not working properly

**Symptom:**
```
"Undefined reference to vtable for..."
```

**Cause:** CMake automoc not enabled or not finding files.

**Solution:**
```cmake
set(CMAKE_AUTOMOC ON)              # Enable automoc
set(CMAKE_AUTORCC ON)              # Enable autorcc for QRC files
set(CMAKE_AUTOUIC ON)              # Enable autouic for UI files
```

---

#### ❌ Changes to .ui or .qrc files not reflected

**Symptom:**
You edit a UI file or QRC file but changes don't appear.

**Cause:** CMake cache not updated.

**Solution:**
```bash
# Clean and rebuild
cmake --build . --target clean
cmake --build .
```

Or delete build directory entirely:
```bash
rm -rf build
mkdir build && cd build
cmake ..
cmake --build .
```

---

### Cross-Platform Issues

#### ❌ App works on Windows but not macOS

**Common causes & solutions:**

1. **Path issues** (/ vs \\):
   ```cmake
   # Use CMake's cross-platform path features
   file(TO_NATIVE_PATH "${CMAKE_CURRENT_SOURCE_DIR}" NATIVE_PATH)
   ```

2. **Library linking difference**:
   ```cmake
   target_link_libraries(myapp PRIVATE
       Qt6::Core
       Qt6::Gui
   )
   # Qt CMake config automatically handles platform differences
   ```

3. **Use qt_configure_platform()**:
   ```cmake
   qt_configure_platform(myapp)
   ```

---

#### ❌ Different behavior on Linux vs Windows

**Common differences:**

| Windows | Linux | Solution |
|---------|-------|----------|
| Case-insensitive paths | Case-sensitive | Use exact paths |
| `.dll` plugins | `.so` libraries | Use `qt_auto_deploy()` |
| `\` path separator | `/` separator | Use CMake path functions |
| Visual Studio build system | Make/Ninja | Use `cmake --build` |

**Solution Option:**
```cmake
if(WIN32)
    # Windows-specific
elseif(APPLE)
    # macOS-specific
elseif(UNIX)
    # Linux-specific
endif()
```

Or use `qt_configure_platform()`:
```cmake
qt_configure_platform(myapp)
```

---

### Installation & Deployment

#### ❌ Installer doesn't include all necessary files

**Solution:**
```cmake
# Use deployment helper
qt_auto_deploy(TARGET myapp DEPLOY_DIR "${CMAKE_BINARY_DIR}/deploy")

# In your installer/packaging script, include:
install(DIRECTORY "${CMAKE_BINARY_DIR}/deploy/" 
        DESTINATION ".")
```

---

#### ❌ App works in development but fails in production

**Symptom:**
Works when Qt is installed, fails when Qt is not installed.

**Cause:** Dependencies not bundled properly.

**Solution:**
1. **Use deployment function**:
   ```cmake
   qt_auto_deploy(TARGET myapp)
   ```

2. **Test in deploy directory**:
   ```bash
   cmake --install . --prefix ./test_deploy
   cd test_deploy
   ./myapp  # Test without Qt in PATH
   ```

---

## Debugging Tips

### Enable Verbose Output

```bash
cmake --build . --verbose
```

### Check Qt Configuration

```cmake
# Add this to your CMakeLists.txt
qt_print_config()

# Or add this debug line
message(STATUS "Qt6_FOUND: ${Qt6_FOUND}")
message(STATUS "Qt6_VERSION: ${Qt6_VERSION}")
message(STATUS "Qt6_DIR: ${Qt6_DIR}")
```

### Check Include Paths

```bash
# Check what CMake sees
cmake -B build --trace 2>&1 | grep -i "qt"
```

### Enable Qt Debug Output

```bash
# At runtime, enable QT debug output
export QT_DEBUG_PLUGINS=1        # Linux/macOS
set QT_DEBUG_PLUGINS=1           # Windows

./myapp
```

---

## Still Having Issues?

1. **Check Documentation**: See [docs/API.md](API.md) and [docs/GETTING_STARTED.md](GETTING_STARTED.md)
2. **Search Examples**: Review working examples in `examples/` folder
3. **Check Qt Documentation**: https://doc.qt.io/qt-6/
4. **Report Bug**: Open issue on GitHub with:
   - Qt version
   - CMake version
   - Operating system
   - Complete error output
   - Minimal code reproduction

---

## Performance Tips

### Faster Builds

```cmake
# Use Ninja instead of Visual Studio
cmake -G Ninja ..

# Parallel builds
cmake --build . -j 8  # Use 8 cores
```

### Parallel QML Compilation

```cmake
qt_auto_qml_module(
    TARGET myapp
    URI MyApp
    QML_DIR "${CMAKE_CURRENT_SOURCE_DIR}/qml"
)
# Qt 6 automatically parallelizes QML compilation
```

---

## CMake Best Practices (To Avoid Issues)

✅ **DO:**
- Always use absolute paths for critical files
- Use `find_package()` before using Qt components
- Keep CMakeLists.txt clean and readable
- Test on all target platforms during development
- Use `qt_auto_deploy()` for all production builds

❌ **DON'T:**
- Mix Qt 5 and Qt 6 in one project
- Hard-code paths
- Assume file paths work across platforms
- Skip `target_link_libraries()`
- Assume it will work on all platforms without testing

