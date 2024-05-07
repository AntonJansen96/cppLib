file(GLOB_RECURSE EULER_SOURCES "*.cpp")
add_library(euler ${EULER_SOURCES})
target_include_directories(euler PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

# Install the library
install(TARGETS euler
    ARCHIVE DESTINATION /usr/local/lib
    LIBRARY DESTINATION /usr/local/lib
)

# Install the header files
install(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/
    DESTINATION include
    FILES_MATCHING PATTERN "*.h"
)
