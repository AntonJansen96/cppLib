#include "math.h"

// Returns (a^b) % m
size_t euler::math::powmod(size_t a, size_t b, size_t m)
{
    size_t result = 1;
    while (b > 0)
    {
        if (b & 1)              // Odd b ? a^b = a*a^(b-1).
            result = mulmod(result, a, m);
        
        a = mulmod(a, a, m);    // Even b ? a^b = (a*b)^(b/2).
        
        b >>= 1;
    }

    return result;
}
