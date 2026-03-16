# Contributing to Qt CMake Tools

First off, thank you for considering contributing to Qt CMake Tools! It's people like you that make Qt CMake Tools such a great tool.

## Code of Conduct

This project and everyone participating in it is governed by our Code of Conduct. By participating, you are expected to uphold this code.

## How Can I Contribute?

### Reporting Bugs

Before creating bug reports, please check the issue list as you might find out that you don't need to create one. When you are creating a bug report, please include as many details as possible:

* **Use a clear, descriptive title**
* **Describe the exact steps which reproduce the problem**
* **Provide specific examples to demonstrate the steps**
* **Describe the behavior you observed after following the steps**
* **Explain which behavior you expected to see instead and why**
* **Include screenshots and animated GIFs if possible**
* **Include your environment:**
  - Operating System and version
  - Qt version
  - CMake version
  - Compiler version

### Suggesting Enhancements

Enhancement suggestions are tracked as GitHub issues. When creating an enhancement suggestion, please include:

* **Use a clear, descriptive title**
* **Provide a step-by-step description of the suggested enhancement**
* **Provide specific examples to demonstrate the steps**
* **Describe the current behavior and explain the expected behavior**
* **Explain why this enhancement would be useful**

### Pull Requests

* Fill in the required template
* Follow the styleguides
* End all files with a newline
* Avoid platform-specific code when possible

## Styleguides

### CMake Code Style

* Use 4 spaces for indentation (no tabs)
* Follow function naming: `qt_function_name()`
* Include docstrings at the top of functions
* Add comments for complex logic
* Use `message(STATUS ...)` for informational output

```cmake
# Example CMake style
function(qt_my_function)
    # This function does something useful
    # Usage: qt_my_function(PARAM1 value1)
    
    set(options)
    set(oneValueArgs PARAM1)
    set(multiValueArgs)
    
    cmake_parse_arguments(QMF "${options}" "${oneValueArgs}" "${multiValueArgs}" ${ARGN})
    
    # Implementation here
    message(STATUS "Qt my function: ${QMF_PARAM1}")
endfunction()
```

### C++ Code Style

* Use 4 spaces for indentation
* Braces on the same line
* Use meaningful variable names
* Add comments for non-obvious logic

```cpp
void MyFunction()
{
    // Implementation
    if (condition) {
        doSomething();
    }
}
```

### Documentation Style

* Use Markdown format
* Include code examples where relevant
* Use clear, simple language
* Add table of contents for longer documents
* Include examples and use cases

## Development Setup

### Prerequisites

1. CMake 3.16 or higher
2. Qt 6.5.0 or later
3. C++17 compatible compiler
4. Git

### Setup Instructions

```bash
# Clone the repository
git clone https://github.com/iakshayubale/qt-cmake-tools.git
cd qt-cmake-tools

# Create build directory
mkdir build && cd build

# Configure
cmake .. -DCMAKE_PREFIX_PATH=/path/to/Qt

# Build
cmake --build .

# Run tests
ctest --output-on-failure
```

## Testing

Before submitting a pull request:

1. **Run all tests:**
   ```bash
   cd build
   ctest --output-on-failure
   ```

2. **Build all examples:**
   ```bash
   cmake --build . --target basic-app
   cmake --build . --target widget-app
   cmake --build . --target qml-app
   ```

3. **Test on multiple platforms if possible:**
   - Windows (Visual Studio generator)
   - macOS (Xcode generator)
   - Linux (Unix Makefiles/Ninja)

## Commit Messages

* Use the present tense ("Add feature" not "Added feature")
* Use the imperative mood ("Move cursor to..." not "Moves cursor to...")
* Limit the first line to 72 characters or less
* Reference issues and pull requests liberally after the first line

Example:
```
Add qt_auto_deploy function

This new function automatically configures Qt deployment,
handling plugin bundling and RPATH configuration.

Closes #123
```

## Documentation

* Update README.md if you change functionality
* Update API.md for new functions
* Update CHANGELOG.md with your changes
* Add comments to complex code sections

## Additional Notes

### Issue and Pull Request Labels

| Label | Description |
|-------|-------------|
| `bug` | Something isn't working |
| `enhancement` | New feature or request |
| `documentation` | Improvements or additions to documentation |
| `good first issue` | Good for newcomers |
| `help wanted` | Extra attention is needed |
| `question` | Further information is requested |

## Recognition

Contributors will be recognized in:
- CHANGELOG.md
- Project README.md (if major contribution)
- GitHub contributors page

Thank you for your contributions! 🎉

