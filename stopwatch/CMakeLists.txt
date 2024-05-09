add_library(stopwatch profile.cpp stopwatch.cpp time.cpp)
target_include_directories(stopwatch PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
