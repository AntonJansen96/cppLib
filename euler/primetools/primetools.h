#ifndef CPPLIB_EULER_PRIMETOOLS_H
#define CPPLIB_EULER_PRIMETOOLS_H

#include <cmath>
#include <vector>

namespace euler
{

// Class for performing prime-related operations/computations.
class Primetools
{   // Enough primes for 1-1000.
    std::vector<unsigned int> d_primes = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31};
    int d_nPrimes = 11;  // Number of primes in d_primes.
    size_t d_max = 1000; // Maximum number.

  public:
    // Defaulted constructor for Primetools object.
    Primetools() = default;

    // Construct Primetools object with specified d_max.
    // Use this with concurrency as this->expand() is not thread-safe.
    explicit Primetools(size_t setMax);

    // This object is not meant be copyable or movable.
    Primetools(Primetools const &other) = delete;
    Primetools(Primetools &&tmp) = delete;

    // Sieve of Eratosthenes. Generate all primes smaller than uplim.
    std::vector<size_t> sieve(size_t uplim) const;

    // Check whether a number is prime using the classical method.
    bool isPrime(size_t num);

    // Check whether a number is prime using the Miller-Rabin test.
    // Deterministic for all 64 bit numbers.
    bool miller_rabin(size_t num) const;

    // Returns number of primes up to (and including) num.
    size_t primePi(size_t num) const;

    // Generate prime factors of a number (with multiplicity).
    std::vector<size_t> factorPrime(size_t num);

    // Generates prime factors of a number (without multiplicity).
    std::vector<size_t> factorPrimeSingle(size_t num);

    // Generate all factors of a number (note: vector is unsorted).
    std::vector<size_t> factorAll(size_t num);

    // Returns the sum of the factors (divisors) of a number.
    size_t divisorSum(size_t num, int order = 1);

    // Returns the sum of the proper factors (divisors) of a number.
    size_t divisorSumProper(size_t num, int order = 1);

    // Returns the largest nontrivial factor of a number.
    // Returns 1 if number is prime.
    size_t largestFactor(size_t num);

    // Compute the totient of a number.
    size_t totient(size_t num);

    // Check whether a number is amicable.
    bool isAmicable(size_t num);

  private:
    // Expands d_max by factor 4 and d_primes by factor 2.
    void expand();

    // To-do: look for faster version of std::sqrt.
    // We only need to integer part.
    unsigned int fastRoot(size_t num) const;
};

} // namespace euler

// To-do: look for faster version of std::sqrt.
inline unsigned int euler::Primetools::fastRoot(size_t num) const
{
    return std::sqrt(num);
}

#endif
