# Build Instructions for Qt CMake Tools

## Prerequisites

**Required:**
- CMake 3.16 or higher
- Qt 6.5.0 or later (with development files)
- C++17 compatible compiler

**Optional:**
- Git (for version control)
- Ninja (for faster builds)
- Visual Studio (Windows) / Xcode (macOS) / GCC (Linux)

---

## Installation Instructions

### 1. Prerequisites Installation

#### Windows
```powershell
# Install Qt 6.5.0 from https://www.qt.io/download-open-source
# Install CMake from https://cmake.org/download/
# Visual Studio 2019 or 2022 (Community Edition is free)
```

#### macOS
```bash
# Using Homebrew
brew install cmake qt
```

Or download Qt from: https://www.qt.io/download-open-source

#### Linux (Ubuntu/Debian)
```bash
sudo apt-get install cmake qt6-base-dev qt6-tools-dev
```

#### Linux (Fedora/RHEL)
```bash
sudo dnf install cmake qt6-qtbase-devel
```

---

## Building Qt CMake Tools

### Step 1: Clone or Extract

```bash
# If using git
git clone https://github.com/iakshayubale/qt-cmake-tools.git
cd qt-cmake-tools    # ⚠️ IMPORTANT: Enter the project directory!

# Or if you downloaded as ZIP
cd /path/to/qt-cmake-tools    # ⚠️ IMPORTANT: Navigate INTO the project folder
```

**Key Point:** You must be INSIDE the `qt-cmake-tools` directory where `CMakeLists.txt` exists.
This is NOT the parent folder - it's the actual project folder.



### Step 2: Configure Build

#### Windows (Visual Studio)
```powershell
mkdir build
cd build

# Set Qt path for your installation
$env:Qt6_DIR = "C:\Qt\6.5.0\msvc2019_64\lib\cmake\Qt6"

cmake .. -G "Visual Studio 17 2022" -DCMAKE_PREFIX_PATH="C:\Qt\6.5.0\msvc2019_64"

# Or use Ninja for faster builds
cmake .. -G "Ninja" -DCMAKE_PREFIX_PATH="C:\Qt\6.5.0\msvc2019_64"
```

#### Windows Subsystem for Linux (WSL)
```bash
# IMPORTANT: Navigate into the qt-cmake-tools project directory
cd /mnt/c/Users/aksha/Downloads/git/qt-cmake-tools

# Create build directory
mkdir build
cd build

# WSL runs Linux, so use Unix Makefiles or Ninja
# First install Qt for Linux if not already done:
# sudo apt-get install qt6-base-dev qt6-tools-dev (Ubuntu/Debian)
# sudo dnf install qt6-qtbase-devel (Fedora/RHEL)

# If Qt is installed at standard location:
cmake .. -G "Unix Makefiles"

# Or if Qt is installed at custom location (Windows path converted to WSL):
# /mnt/c/Qt/6.5.0/gcc_64 corresponds to C:\Qt\6.5.0\gcc_64
cmake .. -G "Unix Makefiles" -DCMAKE_PREFIX_PATH="/mnt/c/Qt/6.5.0/gcc_64"

# For faster builds with Ninja:
cmake .. -G "Ninja" -DCMAKE_PREFIX_PATH="/mnt/c/Qt/6.5.0/gcc_64"
```

#### macOS (Xcode or Unix Makefiles)
```bash
mkdir build
cd build

# Using Xcode
cmake .. -G Xcode -DCMAKE_PREFIX_PATH=/Users/username/Qt/6.5.0/macos

# Or using Unix Makefiles
cmake .. -DCMAKE_PREFIX_PATH=/Users/username/Qt/6.5.0/macos
```

#### Linux
```bash
mkdir build
cd build

cmake .. -DCMAKE_PREFIX_PATH=/opt/Qt/6.5.0/gcc_64
```

### Step 3: Build

#### Windows (Visual Studio)
```powershell
# Using Solution
cmake --build . --config Release

# Alternative: Open sln file in Visual Studio
start qt-cmake-tools.sln
```

#### macOS/Linux
```bash
# Using all available cores
cmake --build . -j$(nproc)

# Or specific number of cores
cmake --build . -j 4

# With Ninja
cmake --build . -- -j 8
```

### Step 4: Run Tests

```bash
# From build directory
ctest --output-on-failure

# Or with verbose output
ctest --output-on-failure -V
```

### Step 5: Build Examples

```bash
# Examples are built automatically, but to test individually:
cmake --build . --target basic-app
cmake --build . --target widget-app
cmake --build . --target qml-app
```

---

## Using Qt CMake Tools in Your Project

### Method 1: Direct Inclusion (Recommended for Quick Start)

```bash
# Copy cmake folder to your project
cp -r qt-cmake-tools/cmake your_project/

cd your_project
mkdir build && cd build
cmake .. -DCMAKE_PREFIX_PATH=/path/to/Qt/installation
cmake --build .
```

### Method 2: Installation (For System-Wide Use)

```bash
cd qt-cmake-tools/build

# Install to default location
cmake --install . --prefix ./install

# Or install to system location (Linux/macOS)
sudo cmake --install . --prefix /usr/local

# Windows (requires Visual Studio with admin)
cmake --install . --prefix "C:\Program Files\qt-cmake-tools"
```

Then in your CMakeLists.txt:
```cmake
find_package(qt-cmake-tools REQUIRED)
```

---

## Troubleshooting Build Issues

### "Qt not found"

**Solution:**
```bash
# Option 1: Set Qt path during configuration
cmake .. -DCMAKE_PREFIX_PATH=/path/to/Qt/installation

# Option 2: Set environment variable
export Qt6_DIR=/path/to/Qt/installation/lib/cmake/Qt6

# Option 3: Set before configuration
cmake .. -DQt6_DIR=/path/to/Qt/installation/lib/cmake/Qt6
```

### "cmake: command not found"

**Windows:**
- Install from: https://cmake.org/download/
- Or add to system PATH

**macOS:**
```bash
brew install cmake
```

**Linux:**
```bash
sudo apt install cmake  # Ubuntu/Debian
sudo dnf install cmake  # Fedora
```

### "does not appear to contain CMakeLists.txt" (WSL)

This happens when cmake can't find CMakeLists.txt. The most common cause is being in the wrong directory.

**Solution:**

```bash
# ❌ WRONG - You're in the parent directory
cd /mnt/c/Users/aksha/Downloads/git
# CMakeLists.txt is NOT here - it's inside qt-cmake-tools!

# ✅ CORRECT - Enter the actual project directory
cd /mnt/c/Users/aksha/Downloads/git/qt-cmake-tools

# Verify CMakeLists.txt exists
ls -la CMakeLists.txt   # Should show the file

# Remove old build
rm -rf build

# Create fresh build directory
mkdir -p build
cd build

# Run cmake from the build directory (note the '..' points to parent = source dir)
cmake .. -G "Unix Makefiles"

# Build
cmake --build . -j4
```

**Key Points:**
1. **You must be INSIDE `qt-cmake-tools/` directory** - this is where CMakeLists.txt lives
2. You then create a `build/` subdirectory inside `qt-cmake-tools/`
3. Run `cmake ..` from the `build/` directory
4. The `..` points to the parent directory which contains CMakeLists.txt

**Directory Tree:**
```
qt-cmake-tools/
├── CMakeLists.txt          ← The file CMake is looking for
├── cmake/
├── examples/
├── tests/
└── build/                  ← Create this, and run cmake from here
    └── (cmake files will be created here)
```

### Compiler errors

Ensure you have a C++17 compatible compiler:

**Windows:**
- Visual Studio 2019 or later

**macOS:**
- Xcode 11.0 or later (includes clang with C++17 support)

**Linux:**
- GCC 7.0 or later
- Clang 5.0 or later

---

## Build Flags

### Debug Build
```bash
cmake .. -DCMAKE_BUILD_TYPE=Debug
```

### Release Build (Optimized)
```bash
cmake .. -DCMAKE_BUILD_TYPE=Release
```

### Enable Testing
```bash
cmake .. -DBUILD_TESTING=ON
```

### Verbose Output
```bash
cmake --build . --verbose
```

---

## Clean Build

To completely clean and rebuild:

```bash
# Remove build directory
rm -rf build

# Recreate and build
mkdir build && cd build
cmake ..
cmake --build .
```

---

## Installing CMake on Each Platform

### Windows
1. Download from: https://cmake.org/download/
2. Run the installer
3. Choose "Add CMake to system PATH" during installation
4. Restart terminal for PATH to update

### macOS
```bash
# Option 1: Homebrew
brew install cmake

# Option 2: Manual download from https://cmake.org/download/
# Then add to PATH:
export PATH="/path/to/cmake/bin:$PATH"
```

### Linux

**Ubuntu/Debian:**
```bash
sudo apt-get install cmake
```

**Fedora/RHEL:**
```bash
sudo dnf install cmake
```

**CentOS:**
```bash
sudo yum install cmake
```

**Arch:**
```bash
sudo pacman -S cmake
```

---

## Next Steps

Once built:

1. **Try Examples:**
   ```bash
   ./examples/basic-app/basic-app
   ./examples/widget-app/widget-app
   ./examples/qml-app/qml-app
   ```

2. **Read Documentation:**
   - [API Documentation](docs/API.md)
   - [Getting Started Guide](docs/GETTING_STARTED.md)
   - [Troubleshooting](docs/TROUBLESHOOTING.md)

3. **Create Your Own Project:**
   ```cmake
   qt_setup_project(my_awesome_app TYPE widget)
   ```

---

## Advanced Options

### Using a Different Qt Installation

```bash
cmake .. -DCMAKE_PREFIX_PATH=/custom/qt/path/lib/cmake
```

### Using Ninja Instead of Visual Studio (Windows)

```powershell
# Install Ninja (requires Chocolatey or manual installation)
choco install ninja

# Configure with Ninja
cmake .. -G Ninja -DCMAKE_PREFIX_PATH="C:\Qt\6.5.0\msvc2019_64"
cmake --build .  # Faster with Ninja!
```

### Static Build

```bash
cmake .. -DBUILD_SHARED_LIBS=OFF
```

### Custom Installation Prefix

```bash
cmake --install . --prefix C:/my/custom/install/path
```

---

## Support

If you encounter issues:

1. Check [TROUBLESHOOTING.md](docs/TROUBLESHOOTING.md)
2. Review [GETTING_STARTED.md](docs/GETTING_STARTED.md)
3. Check existing GitHub issues
4. Create a new issue with:
   - OS and version
   - CMake version (`cmake --version`)
   - Qt version (`qmake --version` or check Qt Creator)
   - Complete error output
   - Steps to reproduce

