# Qt CMake Tools - Changelog

All notable changes to this project will be documented in this file.

The format is based on [Keep a Changelog](https://keepachangelog.com/en/1.0.0/),
and this project adheres to [Semantic Versioning](https://semver.org/spec/v2.0.0.html).

---

## [1.0.0] - 2026-03-16

### Added
- **QtAutoDeploy.cmake** - Automatic Qt deployment configuration
  - Plugin discovery and bundling
  - RPATH configuration for Unix-like systems
  - Cross-platform deployment setup
  - Support for Qt 5 and Qt 6

- **QtAutoQmlModule.cmake** - Automatic QML module discovery
  - Recursive QML file discovery
  - Automatic qmldir generation
  - Qt 6 QML module registration
  - Helper functions for QML file listing

- **QtSetupProject.cmake** - Project scaffolding and initialization
  - Quick project structure generation
  - Support for console, widget, and QML project types
  - Automatic CMakeLists.txt generation
  - .gitignore template

- **QtUtils.cmake** - General-purpose utilities
  - Configuration summary function
  - Strict compiler warning enablement
  - Test integration helpers
  - Platform-specific configuration
  - Application bundling support

- **Comprehensive Documentation**
  - API Documentation (docs/API.md)
  - Getting Started Guide (docs/GETTING_STARTED.md)
  - Troubleshooting Guide (docs/TROUBLESHOOTING.md)
  - Build Instructions (BUILD.md)

- **Example Projects**
  - Basic console application
  - Widget-based GUI application
  - QML/Quick application

- **Unit Tests**
  - CMake module loading tests
  - Qt functionality tests
  - Signal/slot tests

- **Additional Files**
  - User-friendly README with analogies
  - MIT License
  - This changelog

### Features

#### Module: QtAutoDeploy
- ✅ Automatic plugin detection and copying
- ✅ Cross-platform RPATH configuration
- ✅ Support for Qt 5 and Qt 6
- ✅ Windows, macOS, and Linux support
- ✅ Deployment directory configuration

#### Module: QtAutoQmlModule
- ✅ Recursive QML file discovery (Qt 6)
- ✅ Automatic qmldir file generation
- ✅ URI-based module registration
- ✅ Version specification support
- ✅ Resource path configuration

#### Module: QtSetupProject
- ✅ Rapid project scaffolding
- ✅ Project type selection (console, widget, QML)
- ✅ Automatic directory structure creation
- ✅ CMakeLists.txt template generation
- ✅ Basic source code examples

#### Module: QtUtils
- ✅ Configuration reporting
- ✅ Compiler warning configuration
- ✅ Test integration
- ✅ Qt version detection
- ✅ Platform-specific settings

### Documentation

- **README.md** - Main project documentation with user-friendly analogies
- **docs/API.md** - Complete API reference for all functions
- **docs/GETTING_STARTED.md** - Step-by-step quick start guide
- **docs/TROUBLESHOOTING.md** - Common issues and solutions
- **BUILD.md** - Comprehensive build instructions for all platforms
- **tests/README.md** - Testing guide and procedures

### Examples

- **basic-app** - Simple console application
  - Demonstrates basic CMake setup
  - Shows Qt Core usage
  
- **widget-app** - Qt Widget application
  - Traditional GUI application
  - MainWindow implementation
  - Button interaction example

- **qml_app** - Qt Quick/QML application
  - Modern QML user interface
  - Auto-detected QML module
  - Interactive components

### Project Structure

```
qt-cmake-tools/
├── cmake/                    # CMake modules
├── examples/                 # Working examples
├── docs/                     # Documentation
├── tests/                    # Unit tests
├── BUILD.md                  # Build instructions
├── README.md                 # Project overview
├── LICENSE                   # MIT License
└── CMakeLists.txt            # Root CMake file
```

---

## Future Roadmap

### Version 1.1.0 (Planned)
- [ ] VS Code extension for project generation
- [ ] CMake presets support
- [ ] Qt Designer UI file integration
- [ ] Internationalization (i18n) helpers

### Version 1.2.0 (Planned)
- [ ] Testing framework integration
- [ ] Code generation from templates
- [ ] Automated packaging tools
- [ ] Desktop application installer creation

### Version 2.0.0 (Future)
- [ ] WebAssembly support
- [ ] Mobile (Android/iOS) deployment
- [ ] CI/CD integration templates
- [ ] Docker support

---

## Known Limitations

- Qt 6 QML auto-discovery features require Qt 6.2 or later
- Qt 5 has limited QML module auto-registration (Qt 6 feature)
- RPATH configuration is primarily for Unix-like systems
- Windows plugin loading requires proper PATH configuration

---

## Contributing

Contributions are welcome! Please see:
- **Issues**: Report bugs or request features
- **Pull Requests**: Submit improvements and fixes

---

## License

This project is licensed under the MIT License - see the [LICENSE](LICENSE) file for details.

---

## Acknowledgments

- Qt Framework community for excellent documentation
- CMake developers for comprehensive build system
- All contributors and users who provided feedback

---

## Versioning

This project follows [Semantic Versioning](https://semver.org/):
- MAJOR version for incompatible API changes
- MINOR version for backwards-compatible functionality
- PATCH version for backwards-compatible bug fixes

