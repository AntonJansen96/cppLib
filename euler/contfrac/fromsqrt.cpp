#include "../../math/math.h"
#include "../euler.h"
#include "contfrac.h"
#include <set>
#include <tuple>

namespace euler::contfrac
{

// Converts a square root N to a continued fraction representation.
// The optional lim is a limit for the number of coefficients in the continued fraction.
// If set to zero, will compute until full period is found.
std::vector<size_t> fromsqrt(size_t N, size_t lim)
{
    if (euler::isSquare(N))
        return std::vector<size_t>{math::isqrt(N)};

    size_t m = 0;
    size_t d = 1;
    size_t a = math::isqrt(N);
    std::vector<size_t> cf{a};

    if (lim)
    {
        for (size_t i = 0; i != lim; ++i)
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
        std::set<std::tuple<size_t, size_t, size_t>> states;
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

} // namespace euler::contfrac
