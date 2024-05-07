#include "primetools.h"

namespace {

std::vector<size_t> factors;

void findFactors(size_t num, std::vector<size_t> const &pFacs, size_t idx, size_t factor)
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
std::vector<size_t> euler::Primetools::factorAll(size_t num)
{
    factors.clear();

    findFactors(num, this->factorPrimeSingle(num), 0, 1);

    return factors;
}

// OLD (this is a lot slower).

// std::set<size_t> euler::Primetools::factorAll(size_t num)
// {   // First obtain the prime factors of the num.
//     std::vector<size_t> const pFactors{factorPrime(num)};
    
//     size_t iter;
//     std::set<size_t> factors = {1};
//                     // comb != 2^pFactors.size() 
//     for (int comb = 1; comb != (1 << pFactors.size()); ++comb)
//     {
//         iter = 1;

//         for (size_t idx = 0; idx != pFactors.size(); ++idx)
//             if (comb & 1 << idx)
//                 iter *= pFactors[idx];

//         factors.insert(iter);
//     }

//     return factors;
// }
