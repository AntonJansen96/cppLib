#include "math.h"
#include <algorithm>

namespace math
{

// Euclidian algorithm. Returns the greatest common denominator of a, b.
uInt gcd(uInt a, uInt b)
{
#ifdef __GNUC__ // This is around 60% faster using specific CPU instructions.
                // Source https://euler.stephan-brumme.com/toolbox/
    if (a == 0)
        return b;

    if (b == 0)
        return a;

    // MSVC++: _BitScanForward intrinsic instead
    auto shift = __builtin_ctz(a | b);
    a >>= __builtin_ctz(a);
    do
    {
        b >>= __builtin_ctz(b);
        if (a > b)
            std::swap(a, b);

        b -= a;
    } while (b != 0);

    return a << shift;

#else
    // standard GCD
    while (b)
        b ^= a ^= b ^= a %= b;

    return a;

#endif
}

} // Namespace math.
