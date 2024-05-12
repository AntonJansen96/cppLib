#include "../euler/euler.h"
#include "../math/math.h"
#include "fractions.h"
#include <set>
#include <tuple>

namespace fractions
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

// Converts a square root N to a continued fraction representation.
// The optional lim is a limit for the number of coefficients in the continued fraction.
// If set to zero, will compute until full period is found.
std::vector<uInt> fromsqrt(uInt N, uInt lim)
{
    if (euler::isSquare(N))
        return std::vector<uInt>{math::isqrt(N)};

    uInt m = 0;
    uInt d = 1;
    uInt a = math::isqrt(N);
    std::vector<uInt> cf{a};

    if (lim)
    {
        for (uInt i = 0; i != lim; ++i)
        {
            m = d * a - m;
            d = (N - m * m) / d;
            a = (math::isqrt(N) + m) / d;
            cf.push_back(a);
        }
        return cf;
    }
    else
    {
        std::set<std::tuple<uInt, uInt, uInt>> states;
        while (states.find(std::make_tuple(m, d, a)) == states.end())
        {
            states.insert(std::make_tuple(m, d, a));
            m = d * a - m;
            d = (N - m * m) / d;
            a = (math::isqrt(N) + m) / d;
            cf.push_back(a);
        }
        cf.pop_back();
        return cf;
    }
}

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

} // namespace fractions.
