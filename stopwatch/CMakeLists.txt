set (STOPWATCH_SOURCES
    format.cpp
    profile.cpp
    sleep.cpp
    stopwatch.cpp
)

add_library(stopwatch ${STOPWATCH_SOURCES})
target_include_directories(stopwatch PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
