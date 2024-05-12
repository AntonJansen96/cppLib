set (FRACTIONS_SOURCES
    fractions.cpp
    continued.cpp
)

add_library(fractions ${FRACTIONS_SOURCES})
target_include_directories(fractions PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
include_directories(${CMAKE_CURRENT_SOURCE_DIR})
target_link_libraries(fractions euler math)
