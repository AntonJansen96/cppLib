set (UTILITY_SOURCES
)

add_library(utility INTERFACE)
target_include_directories(utility INTERFACE ${CMAKE_CURRENT_SOURCE_DIR})
include_directories(${CMAKE_CURRENT_SOURCE_DIR})
target_link_libraries(utility)
