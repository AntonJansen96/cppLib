#include "../euler.h"
#include <cmath>

// Returns the sum of the digits of num.
size_t euler::sumDigits(size_t num)
{
    size_t count = 0;
    
    while (num)
    {
        count += num % 10;
        num = floor(num / 10);
    }
    return count;
}
