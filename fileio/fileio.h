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

// Read a column from a file into a vector of std::strings.
std::vector<std::string> loadCol_s(std::string const &filename, size_t col = 0,
                                   size_t header = 0);

// Read a column from a file into a vector of signed 64-bit integers.
std::vector<int_fast64_t> loadCol_i(std::string const &filename, size_t col = 0,
                                    size_t header = 0);

// Read a column from a file into a vector of 64-bit floating point numbers.
std::vector<double> loadCol_f(std::string const &filename, size_t col, size_t header);

// Read a .xvg file into a tuple of vectors of 64-bit floating point numbers.
std::vector<std::vector<double>> loadxvg(std::string const &filename);

} // namespace fileio

#endif
