#include "primetools.h"

// Generate prime pFactors of a number.
std::vector<size_t> euler::Primetools::factorPrimeSingle(size_t num)
{
    std::vector<size_t> pFactors;
    size_t prime;
    int idx = 1;                        // Start at second prime in d_primes
                                        // (3) because we already checked 2.
    if (((num >> 1) << 1) == num)       // if num % 2 == 0
    {
        pFactors.push_back(2);          // Only do this once.
        
        while (((num >> 1) << 1) == num)    // while num % 2 == 0
            num >>= 1;                      // num /= 2
    }
                                        // Only have to check up until root of
    while (d_primes[idx] <= fastRoot(num))  
    {                                   // num.
        prime = d_primes[idx];          
        
        if (num % prime == 0)
        {
            pFactors.push_back(prime);      // Only do this once.

            while (num % prime == 0)        // While num is divisible by prime
                num /= prime;               // divide.
        }

        ++idx;
        
        if (idx == d_nPrimes)           // If we have reached the end of the
            this->expand();             // current d_primes vector, call
    }                                   // expand() (i.e. double the vector).
  
    if (num > 2)                        // If at the end we're left with a
        pFactors.push_back(num);        // number larger than two, it must be
                                        // a prime so add to PFactors.
    return pFactors;
}
