#ifndef PRIMETOOLS_H
#define PRIMETOOLS_H

#include <vector>
#include <set>

namespace euler {

// Class for performing prime-related operations/computations.
class Primetools
{
    size_t d_uplim;
    std::vector<size_t> d_primes;

    public:
        // Construct Primetools object by specifying largest number to be analyzed.
        // Default is sizeof(32-bit integer) but can be set accordingly.
        Primetools(size_t uplim = 4'294'967'295);

        // Sieve of Eratosthenes. Generate all prime numbers smaller than uplim.
        std::vector<size_t> sieve(size_t uplim) const;

        // Check whether a number is prime.
        bool isPrime(size_t num) const;

        // Check whether a number is amicable.
        bool isAmicable(size_t num) const;

        // Generate prime factors of a number.
        std::vector<size_t> primeFacs(size_t num) const;

        // Generate all factors of a number.
        std::set<size_t> factors(size_t num) const;

        // Compute the totient of a number.
        size_t totient(size_t num) const;

        // Returns the maximum number that can be analyzed.
        size_t uplim() const;

        // Returns the internal array of primes.
        std::vector<size_t> data() const;
};

} // Namespace.

// Returns the maximum number that can be analyzed.
inline size_t euler::Primetools::uplim() const
{
    return d_uplim;
}

// Returns the internal array of primes.
inline std::vector<size_t> euler::Primetools::data() const
{
    return d_primes;
}

#endif
