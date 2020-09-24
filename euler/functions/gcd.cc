#include "../euler.h"

// Euclidean algorithm. Returns greatest common denominator of a and b.
size_t euler::gcd(size_t a, size_t b)
{
    size_t temp;
    
    while (b != 0)
    {
        temp = a;
        a = b; b = temp % b;
    }

    return a;
}
