set (FRACTIONS_SOURCES
    fractions.cpp
)

add_library(fractions ${FRACTIONS_SOURCES})
target_include_directories(fractions PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
