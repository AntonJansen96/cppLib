#include "primetools.h"
#include <cmath>

// Generate prime factors of a number.
std::vector<size_t> euler::Primetools::primeFacs(size_t num) const
{
    std::vector<size_t> factors;
    size_t prime, idx = 0;

    while (((num >> 1) << 1) == num)
    {
        factors.push_back(2);
        num >>= 1;
    }

    while (d_primes[idx] <= sqrt(num))
    {
        prime = d_primes[idx];
        
        while (num % prime == 0)
        {
            factors.push_back(prime);
            num /= prime;
        }
        
        ++idx;
    }
  
    if (num > 2)
        factors.push_back(num);
    
    return factors;
}
