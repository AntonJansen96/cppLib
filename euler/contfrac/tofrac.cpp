#include "contfrac.h"

namespace euler::contfrac
{

// Converts a continued fraction back to a fraction p/q.
Fraction tofrac(std::vector<size_t> const &cf)
{
    size_t p = 1;
    size_t q = 0;
    for (size_t idx = cf.size() - 1; idx > 0; --idx)
    {
        std::swap(p, q);
        p += cf[idx] * q;
    }

    return Fraction(p, q);
}

} // namespace euler::contfrac
