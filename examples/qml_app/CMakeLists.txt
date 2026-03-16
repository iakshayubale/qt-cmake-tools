cmake_minimum_required(VERSION 3.16)
project(qml-app)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

find_package(Qt6 COMPONENTS
    Core
    Gui
    Qml
    Quick
    REQUIRED)

set(SOURCES
    src/main.cpp
)

set(QML_FILES
    qml/main.qml
)

add_executable(qml-app ${SOURCES} ${QML_FILES})

# Create QML resource file
qt_add_qml_module(qml-app
    URI QmlApp
    QML_FILES ${QML_FILES}
)

target_link_libraries(qml-app PRIVATE
    Qt6::Core
    Qt6::Gui
    Qt6::Qml
    Qt6::Quick
)

# Install target
install(TARGETS qml-app RUNTIME DESTINATION bin)

message(STATUS "Configured: qml-app example")
