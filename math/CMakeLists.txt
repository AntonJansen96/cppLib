file(GLOB_RECURSE MATH_SOURCES "*.cpp")
add_library(math ${MATH_SOURCES})
target_include_directories(math PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
