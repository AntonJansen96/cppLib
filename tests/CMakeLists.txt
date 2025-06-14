cmake_minimum_required(VERSION 3.10)

set(CMAKE_C_COMPILER "/opt/homebrew/bin/gcc-15")
set(CMAKE_CXX_COMPILER "/opt/homebrew/bin/g++-15")
set(CMAKE_CXX_FLAGS "-Wall -std=c++23 -O3 -fopenmp -march=native -funroll-loops -ffast-math -flto -Wl,-w")

project(tests)

option(DEBUG OFF)
option(SINGLE, OFF)
if(SINGLE)
    add_definitions(-DSINGLE)
    message("-- NOTE: will build cpplibs in single-precision.")
endif()

# set(CMAKE_VERBOSE_MAKEFILE ON)
set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include_directories(..)
add_subdirectory(../euler euler)
add_subdirectory(../fileio fileio)
add_subdirectory(../fractions fractions)
add_subdirectory(../math math)
add_subdirectory(../probability probability)
add_subdirectory(../stopwatch stopwatch)
add_subdirectory(../utility utility)

if(NOT DEBUG)
    # EULER
    add_executable(test_euler test_euler.cpp)
    target_link_libraries(test_euler euler)

    # PRIMETOOLS (AS PART OF EULER)
    add_executable(test_primetools test_primetools.cpp)
    target_link_libraries(test_primetools euler)

    # FILEIO
    add_executable(test_fileio test_fileio.cpp)
    target_link_libraries(test_fileio fileio)

    # FRACTIONS
    add_executable(test_fractions test_fractions.cpp)
    target_link_libraries(test_fractions fractions)

    # MATH
    add_executable(test_math test_math.cpp)
    target_link_libraries(test_math math)

    # PYTHONLIKE
    add_executable(test_pythonlike test_pythonlike.cpp)
    target_link_libraries(test_pythonlike) # add pythonlike explicitly if no-longer only an interface lib.

    # RANDOM
    add_executable(test_probability test_probability.cpp)
    target_link_libraries(test_probability probability)

    # STOPWATCH
    add_executable(test_stopwatch test_stopwatch.cpp)
    target_link_libraries(test_stopwatch stopwatch)

    # UTILITY
    add_executable(test_utility test_utility.cpp)
    target_link_libraries(test_utility) # add utility explicitly if no-longer only an interface lib.

    # MAIN TESTS
    add_executable(test_main test_main.cpp)
    target_link_libraries(test_main stopwatch)
endif() # DEBUG

# DEBUG
if(DEBUG)
    add_compile_definitions(DEBUG)
    add_executable(debug debug.cpp)
    target_link_libraries(debug fileio fractions math probability stopwatch utility)
endif()
