# A CMakeLists.txt file for the header-only library

# Set the minimum required version of CMake for a project
cmake_minimum_required(VERSION 3.0)

# Set the project name
project(regex-engine)

# Set the C++ standard to ANSI C++98
set(CMAKE_CXX_STANDARD 98)

# Setup the includes to include the header-only library file `regex.hpp` in the current directory
include_directories(${CMAKE_CURRENT_SOURCE_DIR})

# Add the source file `regex.hpp` to the project
add_library(regex-engine INTERFACE regex.hpp)

# Add the CLI test executable to the project
add_executable(regex tests/cli.cpp)
add_executable(test1 tests/test.cpp)

# Link the CLI executable with the library
target_link_libraries(regex regex-engine)

# Add the test to the project
enable_testing()

# Add the test to the project
add_test(NAME test COMMAND test1)