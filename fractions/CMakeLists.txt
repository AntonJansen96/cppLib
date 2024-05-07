add_library(fractions fractions.cpp)
target_include_directories(fractions PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

# Install the library
install(TARGETS fractions
    ARCHIVE DESTINATION /usr/local/lib
    LIBRARY DESTINATION /usr/local/lib
)

# Install the header files
install(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/
    DESTINATION include
    FILES_MATCHING PATTERN "*.h"
)
