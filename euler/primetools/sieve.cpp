#include "../../math/math.h"
#include "primetools.h"

namespace euler
{

// Sieve of Eratosthenes. Generate all prime numbers smaller than uplim.
std::vector<uInt> euler::Primetools::sieve(uInt uplim) const
{
    std::vector<uInt> primes = {2};
    uInt next = 3; // First number after last prime in primes.

    while (next <= uplim)
    {
        for (uInt prime : primes)
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

} // namespace euler
