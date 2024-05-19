#include "euler.h"
#include <array>
#include <cmath>

namespace euler
{

// Generate primitive Pythagorean triples with perimeter (a + b + c) < perimLim.
std::vector<std::array<uInt, 3>> genPrimTriples(uInt perimLim)
{
    std::vector<std::array<uInt, 3>> array;
    uInt a, b, c;

    for (uInt m = 1; m < sqrt(perimLim); ++m)
        for (uInt n = m + 1; n < sqrt(perimLim); ++n)
            if (!(m & 1 && n & 1) && isCoprime(m, n))
            {
                a = n * n - m * m;
                b = 2 * m * n;
                c = n * n + m * m;

                if (a + b + c <= perimLim)
                    array.push_back({a, b, c});
            }

    return array;
}

// Generate all Pythagorean triples with perimeter (a + b + c) < perimLim.
// Contains duplicate perimeters.
std::vector<std::array<uInt, 3>> genTriples(uInt perimLim)
{
    std::vector<std::array<uInt, 3>> array;
    uInt a, b, c, k;

    for (uInt m = 1; m < sqrt(perimLim); ++m)
        for (uInt n = m + 1; n < sqrt(perimLim); ++n)
            if (!(m & 1 && n & 1) && isCoprime(m, n))
            {
                a = n * n - m * m;
                b = 2 * m * n;
                c = n * n + m * m;

                k = 1;
                while (k * (a + b + c) <= perimLim)
                {
                    array.push_back({k * a, k * b, k * c});
                    ++k;
                }
            }

    return array;
}

} // namespace euler
