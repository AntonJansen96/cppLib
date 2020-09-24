#include "../euler.h"

// Generate all Fibonacci numbers smaller than uplim.
std::vector<size_t> euler::genFibonnaci(size_t uplim)
{
    std::vector<size_t> numbers = {1};
    size_t idx = 1, next = 1;
    
    while (next <= uplim)
    {
        numbers.push_back(next);
        next = numbers[idx - 1] + numbers[idx];
        ++idx;
    }

    return numbers;
}
