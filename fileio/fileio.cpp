#include "fileio.h"

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

} // namespace fileio
