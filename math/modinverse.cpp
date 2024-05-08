#include "math.h"

namespace math
{

// Returns the modular inverse (ax = 1 (mod m)).
uInt modinverse(uInt a, uInt m)
{
    if (m == 0) // Avoid division by zero.
        return 0;

    auto const orig = m;

    uInt s = 0; // Note: s and t can be negative inside the loop.
    uInt t = 1;
    while (a > 1)
    {
        auto tmp = m;
        auto quotient = a / m;
        m = a % m;
        a = tmp;

        auto tmp2 = s;
        s = t - quotient * s;
        t = tmp2;
    }

    return t < 0 ? t + orig : t; // Avoid negative result.
}

} // Namespace math.
