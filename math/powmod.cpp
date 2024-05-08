#include "math.h"

namespace math {

// Returns (a^b) % m
uInt powmod(uInt a, uInt b, uInt m)
{
    uInt result = 1;
    while (b > 0)
    {
        if (b & 1)              // Odd b ? a^b = a*a^(b-1).
            result = mulmod(result, a, m);
        
        a = mulmod(a, a, m);    // Even b ? a^b = (a*b)^(b/2).
        
        b >>= 1;
    }

    return result;
}

} // Namespace math.
