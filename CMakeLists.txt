cmake_minimum_required(VERSION 3.10)

project(cpplib)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_subdirectory(euler)
add_subdirectory(fileio)
add_subdirectory(fractions)
add_subdirectory(math)
add_subdirectory(pythonlike)
add_subdirectory(stopwatch)
add_subdirectory(utility)

# Install the libraries.
install(TARGETS euler fileio fractions math stopwatch utility ARCHIVE DESTINATION /usr/local/lib)

# Install the header files (avoid annoying includes in the header files (.cpp is fine)).
install(DIRECTORY euler/ fileio/ fractions/ math/ pythonlike/ stopwatch/ utility/ DESTINATION /usr/local/include/cpplib FILES_MATCHING PATTERN "*.h")
