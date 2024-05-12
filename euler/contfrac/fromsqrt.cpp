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

} // namespace euler::contfrac
