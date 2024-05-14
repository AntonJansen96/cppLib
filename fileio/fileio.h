#ifndef CPPLIB_FILEIO_H
#define CPPLIB_FILEIO_H

#include <fstream>
#include <sstream>
#include <vector>

namespace fileio
{

// Read a file into a vector of std::strings, delimited by delim.
std::vector<std::string> file2vector(std::string const &filename, char delim = '\n');

// Split a line into a vector of std:string, delimited by delim.
std::vector<std::string> splitline(std::string const &line, char delim);

} // namespace fileio

#endif
