#include "contfrac.h"

namespace euler::contfrac
{

// Converts a continued fraction back to a fraction p/q.
Fraction tofrac(std::vector<uInt> const &cf)
{
    uInt p = 1;
    uInt q = 0;
    for (uInt idx = cf.size() - 1; idx > 0; --idx)
    {
        std::swap(p, q);
        p += cf[idx] * q;
    }

    return Fraction(p, q);
}

} // namespace euler::contfrac
