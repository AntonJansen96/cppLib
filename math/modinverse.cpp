#include "math.h"

namespace math {

uInt modinverse(uInt a, uInt m)
{
    auto const orig = m;

    long s = 0;      // Note: s and t can be negative inside the loop.
    long t = 1;
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

    return t < 0 ? t + orig : t;    // Avoid negative result.
}

} // Namespace math.
