#include "../euler.h"
#include <cmath>
#include <tuple>

// Generate primitive Pythagorean triples with perimeter (a + b + c) < perimLim.
std::tuple<std::vector<size_t>, std::vector<size_t>, std::vector<size_t>> 
euler::genPrimTriples(size_t perimLim)
{
    std::vector<size_t> A, B, C;
    size_t a, b, c;

    for (size_t m = 1; m < sqrt(perimLim); ++m)
        for (size_t n = m + 1; n < sqrt(perimLim); ++n)
            if (!(m & 1 && n & 1) && isCoprime(m, n))
            {
                a = n*n - m*m;
                b = 2 * m * n;
                c = n*n + m*m;

                if (a + b + c <= perimLim)
                {
                    A.push_back(a);
                    B.push_back(b);
                    C.push_back(c);
                }
            }
    
    return std::tuple{A, B, C};
}
