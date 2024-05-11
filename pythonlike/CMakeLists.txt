set (PYTHONLIKE_SOURCES
)

add_library(pythonlike INTERFACE)
target_include_directories(pythonlike INTERFACE ${CMAKE_CURRENT_SOURCE_DIR})
include_directories(${CMAKE_CURRENT_SOURCE_DIR})
target_link_libraries(pythonlike)
