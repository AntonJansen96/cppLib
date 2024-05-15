set (UTILITY_SOURCES
    utility.cpp
)

add_library(utility ${UTILITY_SOURCES})
target_include_directories(utility PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
include_directories(${CMAKE_CURRENT_SOURCE_DIR})
target_link_libraries(utility)
