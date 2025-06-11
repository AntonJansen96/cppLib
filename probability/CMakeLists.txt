set (RANDOM_SOURCES
    probability.cpp
)

add_library(probability ${RANDOM_SOURCES})
target_include_directories(probability PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
include_directories(${CMAKE_CURRENT_SOURCE_DIR})
target_link_libraries(probability euler math)
