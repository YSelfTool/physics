cmake_minimum_required (VERSION 2.6)
project (Physics)
# The version nmber.
set (Physics_VERSION_MAJOR 0)
set (Physics_VERSION_MINOR 0)
set (CXX_STANDARD 11)
set (CXX_STANDARD_REQUIRED ON)
set (CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
set (CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
set (CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

# configure a header file to pass some of the CMake settings
# to the source code
configure_file (
    "${PROJECT_SOURCE_DIR}/src/PhysicsConfig.hpp.in"
    "${PROJECT_BINARY_DIR}/src/PhysicsConfig.hpp"
)

# add the binary tree to the search path for include files
# so that we will find PhysicsConfig.hpp
include_directories("${PROJECT_BINARY_DIR}")
include_directories("${PROJECT_SOURCE_DIR}/src")

add_library(Physics src/vector3.cpp src/rectangle.cpp src/line.cpp)

# add the executable
add_executable(Test test.cpp)
target_link_libraries(Test Physics)
