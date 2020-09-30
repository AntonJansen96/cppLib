#include "../euler.h"

// Returns the sum of the digits of num.
int euler::sumDigits(size_t num)
{
    int count = 0;
    
    while (num)
    {
        count += num % 10;
        num /= 10;
    }
    return count;
}
