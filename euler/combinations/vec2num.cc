#include "combinations.h"

// Transforms a vector of digits into an integer.
size_t euler::Combinations::vector2number(std::vector<int> const &input)
{
    size_t number = 0;
    for (auto digit : input)
        number = number * 10 + digit;

    return number;
}
