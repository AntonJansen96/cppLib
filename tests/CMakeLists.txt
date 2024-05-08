cmake_minimum_required(VERSION 3.10)

set(CMAKE_CXX_COMPILER "/opt/homebrew/bin/g++-13")
set(CMAKE_CXX_FLAGS "-Wall -std=c++20 -O3 -fopenmp -march=native -funroll-loops -ffast-math -flto -Wl,-w")

project(tests)

# set(CMAKE_VERBOSE_MAKEFILE ON)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include_directories(..)
add_subdirectory(../euler euler)
add_subdirectory(../fractions fractions)
add_subdirectory(../math math)
add_subdirectory(../stopwatch stopwatch)

add_executable(tests tests.cpp)
target_link_libraries(tests euler fractions math stopwatch)
