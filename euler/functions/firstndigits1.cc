#include "../euler.h"

// Returns the first N digits from a number.
size_t euler::firstNdigits(size_t num, int N)
{
    while(num >= math::fastpow(10, N))
        num /= 10;
    
    return num;
}
