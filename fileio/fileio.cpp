#include "fileio.h"
#include <cstdint>

namespace fileio
{

// Read a file into a vector of std::strings, delimited by delim.
std::vector<std::string> file2vector(std::string const &filename, char delim)
{
    std::ifstream file(filename);
    std::vector<std::string> array;
    std::string line;
    char ch;

    if (file.is_open())
    {
        while (file.get(ch))
        {
            if (ch == '\n' || ch == delim)
            {
                if (!line.empty())
                    array.push_back(line);

                line.clear();
                continue;
            }

            line.push_back(ch);
        }
        if (!line.empty()) // Flush line, just to be sure.
            array.push_back(line);
    }
    return array;
}

// Split a line into a vector of std:string, delimited by delim.
std::vector<std::string> splitline(std::string const &line, char delim)
{
    std::vector<std::string> tokens;
    std::string token;
    std::istringstream tokenStream(line);

    while (std::getline(tokenStream, token, delim))
        if (!token.empty())
            tokens.push_back(token);

    return tokens;
}

// Read a column from a file into a vector of std::strings.
std::vector<std::string> loadCol_s(std::string const &filename, size_t col,
                                   size_t header)
{
    std::ifstream file(filename);
    std::vector<std::string> array;
    std::string line;

    if (file.is_open())
    { // Skip the #header number of header lines.
        for (size_t i = 0; i != header; ++i)
            std::getline(file, line);

        while (std::getline(file, line))
        {
            std::istringstream tokenStream(line);
            std::string token;
            size_t idx = 0;

            while (std::getline(tokenStream, token, ' '))
            {
                if (token.empty())
                    continue;

                if (idx == col)
                {
                    array.push_back(token);
                    break;
                }

                ++idx;
            }
        }
    }
    return array;
}

// Read a column from a file into a vector of signed 64-bit integers.
std::vector<int_fast64_t> loadCol_i(std::string const &filename, size_t col,
                                    size_t header)
{
    std::vector<int_fast64_t> array;
    for (std::string const &str : loadCol_s(filename, col, header))
        array.push_back(std::stoll(str));
    return array;
}

// Read a column from a file into a vector of 64-bit floating point numbers.
std::vector<double> loadCol_f(std::string const &filename, size_t col, size_t header)
{
    std::vector<double> array;
    for (std::string const &str : loadCol_s(filename, col, header))
        array.push_back(std::stod(str));
    return array;
}

} // namespace fileio
