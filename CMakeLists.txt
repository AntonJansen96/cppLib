cmake_minimum_required(VERSION 3.10)

set(CMAKE_CXX_COMPILER "/opt/homebrew/bin/g++-13")
set(CMAKE_CXX_FLAGS "-Wall -std=c++20 -O3 -fopenmp -march=native -funroll-loops -ffast-math -flto")
# set(CMAKE_VERBOSE_MAKEFILE ON)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_subdirectory(euler)
add_subdirectory(fractions)
add_subdirectory(math)
add_subdirectory(pythonlike)
add_subdirectory(stopwatch)
