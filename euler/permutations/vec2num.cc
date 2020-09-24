#include "permutations.h"

// Transforms a vector of digits into an integer.
size_t euler::Permutations::vector2number(std::vector<int> const &input)
{
    size_t number = 0;
    for (auto digit : input)
        number = number * 10 + digit;

    return number;
}
