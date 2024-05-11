set(FILEIO_SOURCES
    fileio.cpp
)

add_library(fileio ${FILEIO_SOURCES})
target_include_directories(fileio PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
