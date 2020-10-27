#include "math.h"

unsigned int euler::math::modinverse(unsigned int a, unsigned int m)
{
    auto const orig = m;

    int s = 0;      // Note: s and t can be negative inside the loop.
    int t = 1;
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