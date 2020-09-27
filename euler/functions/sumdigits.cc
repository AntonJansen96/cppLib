#include "../euler.h"
#include <cmath>

// Returns the sum of the digits of num.
int euler::sumDigits(size_t num)
{
    int count = 0;
    
    while (num)
    {
        count += num % 10;
        num = std::floor(num / 10);
    }
    return count;
}
