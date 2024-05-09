file(GLOB STOPWATCH_SOURCES "*.cpp")
add_library(stopwatch ${STOPWATCH_SOURCES})
target_include_directories(stopwatch PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
