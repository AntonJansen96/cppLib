#include "contfrac.h"

namespace euler::contfrac
{

// Converts a fraction p/q to a continued fraction representation.
std::vector<uInt> fromfrac(Fraction const &frac)
{
    uInt p = frac.num();
    uInt q = frac.denom();

    std::vector<uInt> cf;
    while (q != 0)
    {
        cf.push_back(p / q);
        p %= q;
        std::swap(p, q);
    }
    return cf;
}

// Converts a fraction p/q to a continued fraction representation.
std::vector<uInt> fromfrac(uInt p, uInt q)
{
    std::vector<uInt> cf;
    while (q != 0)
    {
        cf.push_back(p / q);
        p %= q;
        std::swap(p, q);
    }
    return cf;
}

} // namespace euler::contfrac
