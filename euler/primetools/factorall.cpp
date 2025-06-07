#include "primetools.h"

namespace
{

using uInt = euler::uInt;

std::vector<uInt> factors;

void findFactors(uInt num, std::vector<uInt> const &pFacs, uInt idx, uInt factor)
{
    if (idx == pFacs.size())
    {
        factors.push_back(factor);
        return;
    }

    while (true)
    {
        findFactors(num, pFacs, idx + 1, factor);

        factor *= pFacs[idx];

        if (num % factor != 0)
            break;
    }
}

} // Namespace.

// Generate all factors of a number.
std::vector<uInt> euler::Primetools::factorAll(uInt num)
{
    if (num == 0)
        return std::vector<uInt>{}; // special case for 0.

    factors.clear();

    findFactors(num, this->factorPrimeSingle(num), 0, 1);

    return factors;
}
