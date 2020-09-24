#include "primetools.h"
#include <cmath>

// Check whether a number is prime.
bool euler::Primetools::isPrime(size_t num) const
{
    if (num < 2)
        return false;
    
    size_t idx = 0;
    while (d_primes[idx] <= sqrt(num))
    {
        if (num % d_primes[idx] == 0)
            return false;        
        
        ++idx;
    }

    return true;
}
