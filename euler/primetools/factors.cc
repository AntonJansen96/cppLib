#include "primetools.h"

// Generate all factors of a number.
std::set<size_t> euler::Primetools::factors(size_t num) const
{
    std::vector<size_t> const primefacs(primeFacs(num));
    
    size_t iter;
    std::set<size_t> factors = {1};
    
    for (int comb = 1; comb != (1 << primefacs.size()); ++comb)
    {
        iter = 1;

        for (size_t idx = 0; idx != primefacs.size(); ++idx)
            if (comb & 1 << idx)
                iter *= primefacs[idx];

        factors.insert(iter);
    }

    return factors;
}
