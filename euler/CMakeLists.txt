file(GLOB_RECURSE EULER_SOURCES "*.cpp")
file(GLOB_RECURSE PRIMETOOLS_SOURCES "primetools/*.cpp")
add_library(euler ${EULER_SOURCES} ${PRIMETOOLS_SOURCES})
target_include_directories(euler PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
