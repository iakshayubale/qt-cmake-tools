cmake_minimum_required(VERSION 3.16)
project(widget-app)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

find_package(Qt6 COMPONENTS 
    Core
    Gui
    Widgets
    REQUIRED)

set(SOURCES
    src/main.cpp
    src/mainwindow.cpp
    src/mainwindow.h
)

add_executable(widget-app ${SOURCES})

target_link_libraries(widget-app PRIVATE 
    Qt6::Core
    Qt6::Gui
    Qt6::Widgets
)

# Install target
install(TARGETS widget-app RUNTIME DESTINATION bin)

message(STATUS "Configured: widget-app example")
