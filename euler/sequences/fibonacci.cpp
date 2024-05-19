#include "sequences.h"

namespace euler::sequences
{

// Generate all Fibonacci numbers smaller than uplim.
std::vector<uInt> fibonacci(uInt uplim)
{
    std::vector<uInt> numbers = {0};
    uInt idx = 1, next = 1;

    while (next <= uplim)
    {
        numbers.push_back(next);
        next = numbers[idx - 1] + numbers[idx];
        ++idx;
    }

    return numbers;
}

} // namespace euler::sequences
