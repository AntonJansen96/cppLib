#include "../../math/math.h"
#include "primetools.h"

// Sieve of Eratosthenes. Generate all prime numbers smaller than uplim.
std::vector<size_t> euler::Primetools::sieve(size_t uplim) const
{
    std::vector<size_t> primes = {2};
    size_t next = 3; // First number after last prime in primes.

    while (next <= uplim)
    {
        for (size_t prime : primes)
        {
            if (next % prime == 0) // If next is divisible by a prime, next
                break;             // is not prime. Therefore we break.

            if (prime > math::isqrt(next)) // If the prime > root of next and we
            {                              // still haven't found any primes,
                primes.push_back(next);    // there are none, so add next to
                break;                     // vector of primes.
            }
        }
        next += 2; // increment by 2 because we start at next = 3 and even
    } // even numbers are never prime.
    return primes;
}
