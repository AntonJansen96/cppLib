cmake_minimum_required(VERSION 3.10)

add_library(pythonlike INTERFACE)
target_include_directories(pythonlike INTERFACE ${CMAKE_CURRENT_SOURCE_DIR})

# Install the library
install(TARGETS pythonlike
    ARCHIVE DESTINATION /usr/local/lib
    LIBRARY DESTINATION /usr/local/lib
)

# Install the header files
install(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/
    DESTINATION include
    FILES_MATCHING PATTERN "*.h"
)
