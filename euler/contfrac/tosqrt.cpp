#include "contfrac.h"

namespace euler::contfrac
{

// Converts a continued fraction back to a square root sqrt(N).
// Returns an approximation of the square root as a decimal value.
// Note that unlike the fraction case, the continued fraction representation
// of a square root is periodic. Therefore, the number N resulting from this
// function will be an approximation.
double tosqrt_dec(std::vector<uInt> const &cf, uInt iter)
{
    iter == 0 ? iter = 1 : iter;

    // First we add cf to itself #iter times.
    std::vector<uInt> cfnew;
    for (uInt i = 0; i != iter; ++i)
        cfnew.insert(cfnew.end(), cf.begin() + 1, cf.end());
    cfnew.insert(cfnew.begin(), cf[0]);

    uInt p = 1;
    uInt q = 0;
    // Now go reversed.
    for (auto it = cfnew.rbegin(); it != cfnew.rend(); ++it)
    {
        std::swap(p, q);
        p += *it * q;
    }
    return (p * p) / static_cast<double>(q * q);
}

// Converts a continued fraction back to a square root sqrt(N).
// Returns an approximation of the square root as a Fraction.
// Note that unlike the fraction case, the continued fraction representation
// of a square root is periodic. Therefore, the number N resulting from this
// function will be an approximation.
Fraction tosqrt_frac(std::vector<uInt> const &cf, uInt iter)
{
    iter == 0 ? iter = 1 : iter;

    // First we add cf to itself #iter times.
    std::vector<uInt> cfnew;
    for (uInt i = 0; i != iter; ++i)
        cfnew.insert(cfnew.end(), cf.begin() + 1, cf.end());
    cfnew.insert(cfnew.begin(), cf[0]);

    uInt p = 1;
    uInt q = 0;
    // Now go reversed.
    for (auto it = cfnew.rbegin(); it != cfnew.rend(); ++it)
    {
        std::swap(p, q);
        p += *it * q;
    }
    return Fraction(p, q);
}

} // namespace euler::contfrac
