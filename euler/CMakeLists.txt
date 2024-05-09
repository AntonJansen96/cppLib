file(GLOB_RECURSE EULER_SOURCES "*.cpp")
add_library(euler ${EULER_SOURCES})
target_include_directories(euler PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
