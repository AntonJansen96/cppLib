#ifndef CPPLIB_UTILITY_H
#define CPPLIB_UTILITY_H

#include <algorithm>
#include <string>
#include <vector>

namespace utility
{

// Handles input options when prompting a user.
size_t inputOptionHandler(std::string message, std::vector<std::string> const &options);

// Transforms a vector of digits into an integer.
template <typename Type> Type vec2num(std::vector<Type> const &input)
{
    Type number = 0;
    for (auto const &digit : input)
        number = number * 10 + digit;
    return number;
}

// Transforms a number into a vector of digits.
template <typename Type> std::vector<Type> num2vec(Type number)
{
    std::vector<Type> digits;
    while (number > 0)
    {
        digits.push_back(number % 10);
        number /= 10;
    }
    std::reverse(digits.begin(), digits.end());
    return digits;
}

} // namespace utility

#endif
