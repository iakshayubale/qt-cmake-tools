cmake_minimum_required(VERSION 3.16)
project(basic-app)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_AUTOMOC ON)

find_package(Qt6 COMPONENTS Core REQUIRED)

add_executable(basic-app src/main.cpp)

target_link_libraries(basic-app PRIVATE Qt6::Core)

# Install target
install(TARGETS basic-app RUNTIME DESTINATION bin)

message(STATUS "Configured: basic-app example")
