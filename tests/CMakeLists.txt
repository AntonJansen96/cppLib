cmake_minimum_required(VERSION 3.10)

set(CMAKE_CXX_COMPILER "/opt/homebrew/bin/g++-13")
set(CMAKE_CXX_FLAGS "-Wall -std=c++20 -O3 -fopenmp -march=native -funroll-loops -ffast-math -flto -Wl,-w")

project(tests)

# set(CMAKE_VERBOSE_MAKEFILE ON)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include_directories(..)
add_subdirectory(../euler euler)
add_subdirectory(../fileio fileio)
add_subdirectory(../fractions fractions)
add_subdirectory(../math math)
add_subdirectory(../stopwatch stopwatch)
add_subdirectory(../utility utility)

# EULER
add_executable(test_euler test_euler.cpp)
target_link_libraries(test_euler fileio fractions math stopwatch utility)

# FILEIO
add_executable(test_fileio test_fileio.cpp)
target_link_libraries(test_fileio fileio fractions math stopwatch utility)

# FRACTIONS
add_executable(test_fractions test_fractions.cpp)
target_link_libraries(test_fractions fileio fractions math stopwatch utility)

# MATH
add_executable(test_math test_math.cpp)
target_link_libraries(test_math fileio fractions math stopwatch utility)

# PYTHONLIKE
add_executable(test_pythonlike test_pythonlike.cpp)
target_link_libraries(test_pythonlike fileio fractions math stopwatch utility)

# STOPWATCH
add_executable(test_stopwatch test_stopwatch.cpp)
target_link_libraries(test_stopwatch euler fileio fractions math stopwatch utility)

# UTILITY
add_executable(test_utility test_utility.cpp)
target_link_libraries(test_utility fileio fractions math stopwatch utility)

# MAIN TESTS
add_executable(test_main test_main.cpp)
target_link_libraries(test_main stopwatch)

# DEBUG
add_executable(debug debug.cpp)
target_link_libraries(debug fileio fractions math stopwatch utility)
