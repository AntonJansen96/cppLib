#include "../euler.h"

// Returns the number of of occurances of digit in num.
int euler::countDigits(size_t num, size_t digit)
{
    size_t count = 0;
    
    while (num)
    {
        if (num % 10 == digit)
            ++count;

        num /= 10;
    }
    return count;    
}
