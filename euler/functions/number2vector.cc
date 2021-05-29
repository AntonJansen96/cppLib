#include "../euler.h"
#include <algorithm>

// Converts a number to a vector of digits.
std::vector<size_t> euler::num2vec(size_t num)
{
    std::vector<size_t> numbers;
    
    while (num)
    {
        numbers.push_back(num % 10);
        num /= 10;
    }

    std::reverse(numbers.begin(), numbers.end());

    return numbers;
}
