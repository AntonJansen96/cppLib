#include "../../math/math.h"
#include "primetools.h"

namespace
{

using uInt = euler::uInt;

void findFactors0(uInt num, std::vector<uInt> const &pFacs, uInt idx, uInt factor,
                  uInt &factorSum)
{
    if (idx == pFacs.size())
    {
        ++factorSum;
        return;
    }

    while (true)
    {
        findFactors0(num, pFacs, idx + 1, factor, factorSum);

        factor *= pFacs[idx];

        if (num % factor != 0)
            break;
    }
}

void findFactors1(uInt num, std::vector<uInt> const &pFacs, uInt idx, uInt factor,
                  uInt &factorSum)
{
    if (idx == pFacs.size())
    {
        factorSum += factor;
        return;
    }

    while (true)
    {
        findFactors1(num, pFacs, idx + 1, factor, factorSum);

        factor *= pFacs[idx];

        if (num % factor != 0)
            break;
    }
}

void findFactors2(uInt num, std::vector<uInt> const &pFacs, uInt idx, uInt factor,
                  uInt &factorSum)
{
    if (idx == pFacs.size())
    {
        factorSum += factor * factor;
        return;
    }

    while (true)
    {
        findFactors2(num, pFacs, idx + 1, factor, factorSum);

        factor *= pFacs[idx];

        if (num % factor != 0)
            break;
    }
}

void findFactors3(uInt num, std::vector<uInt> const &pFacs, uInt idx, uInt factor,
                  uInt &factorSum)
{
    if (idx == pFacs.size())
    {
        factorSum += factor * factor * factor;
        return;
    }

    while (true)
    {
        findFactors3(num, pFacs, idx + 1, factor, factorSum);

        factor *= pFacs[idx];

        if (num % factor != 0)
            break;
    }
}

void findFactors4(uInt num, std::vector<uInt> const &pFacs, uInt idx, uInt factor,
                  uInt order, uInt &factorSum)
{
    if (idx == pFacs.size())
    {
        factorSum += math::fastpow(factor, order);
        return;
    }

    while (true)
    {
        findFactors4(num, pFacs, idx + 1, factor, order, factorSum);

        factor *= pFacs[idx];

        if (num % factor != 0)
            break;
    }
}

} // Namespace.

// Return the sum of the factors (divisors) of a number.
uInt euler::Primetools::divisorSum(uInt num, uInt order)
{
    if (num == 0)
        return 0;

    uInt factorSum = 0;

    switch (order)
    {
        case (0):
            findFactors0(num, this->factorPrimeSingle(num), 0, 1, factorSum);
            break;

        case (1):
            findFactors1(num, this->factorPrimeSingle(num), 0, 1, factorSum);
            break;

        case (2):
            findFactors2(num, this->factorPrimeSingle(num), 0, 1, factorSum);
            break;

        case (3):
            findFactors3(num, this->factorPrimeSingle(num), 0, 1, factorSum);
            break;

        default:
            findFactors4(num, this->factorPrimeSingle(num), 0, 1, order, factorSum);
            break;
    }

    return factorSum;
}
