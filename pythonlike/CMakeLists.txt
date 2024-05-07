cmake_minimum_required(VERSION 3.10)

add_library(pythonlike INTERFACE)
target_include_directories(pythonlike INTERFACE ${CMAKE_CURRENT_SOURCE_DIR})
