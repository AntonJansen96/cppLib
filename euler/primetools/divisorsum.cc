#include "primetools.h"

namespace {

size_t factorSum;

void findFactors0(size_t num, std::vector<size_t> const &pFacs, size_t idx, size_t factor)
{
    if (idx == pFacs.size())
    {
        ++factorSum;
        return;
    }

    while (true)
    {
        findFactors0(num, pFacs, idx + 1, factor);

        factor *= pFacs[idx];

        if (num % factor != 0)
            break;
    }
}

void findFactors1(size_t num, std::vector<size_t> const &pFacs, size_t idx, size_t factor)
{
    if (idx == pFacs.size())
    {
        factorSum += factor;
        return;
    }

    while (true)
    {
        findFactors1(num, pFacs, idx + 1, factor);

        factor *= pFacs[idx];

        if (num % factor != 0)
            break;
    }
}

void findFactors2(size_t num, std::vector<size_t> const &pFacs, size_t idx, size_t factor)
{
    if (idx == pFacs.size())
    {
        factorSum += factor * factor;
        return;
    }

    while (true)
    {
        findFactors2(num, pFacs, idx + 1, factor);

        factor *= pFacs[idx];

        if (num % factor != 0)
            break;
    }
}

void findFactors3(size_t num, std::vector<size_t> const &pFacs, size_t idx, size_t factor)
{
    if (idx == pFacs.size())
    {
        factorSum += factor * factor * factor;
        return;
    }

    while (true)
    {
        findFactors3(num, pFacs, idx + 1, factor);

        factor *= pFacs[idx];

        if (num % factor != 0)
            break;
    }
}

void findFactors4(size_t num, std::vector<size_t> const &pFacs, size_t idx, size_t factor, int order)
{
    if (idx == pFacs.size())
    {
        factorSum += std::pow(factor, order);
        return;
    }

    while (true)
    {
        findFactors4(num, pFacs, idx + 1, factor, order);

        factor *= pFacs[idx];

        if (num % factor != 0)
            break;
    }
}

} // Namespace.

// Return the sum of the factors (divisors) of a number.
size_t euler::Primetools::divisorSum(size_t num, int order)
{
    factorSum = 0;

    switch (order)
    {
        case (0):
            findFactors0(num, this->factorPrimeSingle(num), 0, 1);
            break;

        case (1):
            findFactors1(num, this->factorPrimeSingle(num), 0, 1);
            break;

        case (2):
            findFactors2(num, this->factorPrimeSingle(num), 0, 1);
            break;

        case (3):
            findFactors3(num, this->factorPrimeSingle(num), 0, 1);
            break;

        default:
            findFactors4(num, this->factorPrimeSingle(num), 0, 1, order);
            break;
    }

    return factorSum;
}
