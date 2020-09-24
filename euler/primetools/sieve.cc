#include "primetools.h"
#include <cmath>

// Sieve of Eratosthenes. Generate all prime numbers smaller than uplim.
std::vector<size_t> euler::Primetools::sieve(size_t uplim) const
{
    std::vector<size_t> primes = {2};
    size_t next = 3;

    while (next <= uplim)
    {
        for (size_t prime : primes)
        {
            if (next % prime == 0)
                break;

            if (prime > sqrt(next))
            {
                primes.push_back(next);
                break;
            }
        }
        next += 2;
    }
    return primes;
}
