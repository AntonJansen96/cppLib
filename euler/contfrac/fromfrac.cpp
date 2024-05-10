#include "contfrac.h"

namespace euler::contfrac
{

// Converts a fraction p/q to a continued fraction representation.
std::vector<size_t> fromfrac(Fraction const &frac)
{
    size_t p = frac.num();
    size_t q = frac.denom();

    std::vector<size_t> cf;
    while (q != 0)
    {
        cf.push_back(p / q);
        p %= q;
        std::swap(p, q);
    }
    return cf;
}

// Converts a fraction p/q to a continued fraction representation.
std::vector<size_t> fromfrac(size_t p, size_t q)
{
    std::vector<size_t> cf;
    while (q != 0)
    {
        cf.push_back(p / q);
        p %= q;
        std::swap(p, q);
    }
    return cf;
}

} // namespace euler::contfrac
