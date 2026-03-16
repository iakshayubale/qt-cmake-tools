# CMake modules for qt-cmake-tools
# This directory contains reusable CMake functions for Qt development

# Install CMake modules
set(CMAKE_MODULES
    QtAutoDeploy.cmake
    QtAutoQmlModule.cmake
    QtSetupProject.cmake
    QtUtils.cmake
)

install(FILES ${CMAKE_MODULES} 
        DESTINATION lib/cmake/qt-cmake-tools)
