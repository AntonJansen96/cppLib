cmake_minimum_required(VERSION 3.10)
project(MyProject)

set(CMAKE_CXX_COMPILER "/opt/homebrew/bin/g++-13")
set(CMAKE_CXX_FLAGS "-Wall -std=c++20 -O3 -fopenmp -march=native -funroll-loops -ffast-math -flto -Wl,-w")

set(CMAKE_CXX_STANDARD 20)

include_directories(${CMAKE_SOURCE_DIR})

add_library(stopwatch stopwatch/stopwatch.cpp)
add_library(math math/math.cpp)
add_library(fractions fractions/fractions.cpp)

add_executable(main main.cpp)
target_link_libraries(main stopwatch math fractions)
