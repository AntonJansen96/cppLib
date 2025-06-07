#ifndef CPPLIB_EULER_PRIMETOOLS_H
#define CPPLIB_EULER_PRIMETOOLS_H

#include <cstdint>
#include <vector>

namespace euler
{

#ifdef SINGLE
using sInt = int_fast32_t;  // Signed 32-bit integer.
using uInt = uint_fast32_t; // Unsigned 32-bit integer.
#else
using sInt = int_fast64_t;  // Signed 64-bit integer.
using uInt = uint_fast64_t; // Unsigned 64-bit integer.
#endif

// Class for performing prime-related operations/computations.
class Primetools
{ // Enough primes for 1-1000.
    std::vector<uInt> d_primes = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31};
    uInt d_nPrimes = 11; // Number of primes in d_primes.
    uInt d_max = 1000;   // Maximum number.

  public:
    // Defaulted constructor for Primetools object.
    Primetools() = default;

    // Construct Primetools object with specified d_max.
    // Use this with concurrency as this->expand() is not thread-safe.
    explicit Primetools(uInt setMax);

    // This object is not meant be copyable or movable.
    Primetools(Primetools const &other) = delete;
    Primetools(Primetools &&tmp) = delete;

    // Sieve of Eratosthenes. Generate all primes smaller than uplim.
    std::vector<uInt> sieve(uInt uplim) const;

    // Check whether a number is prime using the classical method.
    bool isPrime(uInt num);

    // Check whether a number is prime using the Miller-Rabin test.
    // Deterministic for all 64 bit numbers.
    bool miller_rabin(uInt num) const;

    // Returns number of primes up to (and including) num.
    uInt primePi(uInt num) const;

    // Generate prime factors of a number (with multiplicity).
    std::vector<uInt> factorPrime(uInt num);

    // Generates prime factors of a number (without multiplicity).
    std::vector<uInt> factorPrimeSingle(uInt num);

    // Generate all factors of a number (note: vector is unsorted).
    std::vector<uInt> factorAll(uInt num);

    // Returns the sum of the factors (divisors) of a number.
    uInt divisorSum(uInt num, uInt order = 1);

    // Returns the sum of the proper factors (divisors) of a number.
    uInt divisorSumProper(uInt num, uInt order = 1);

    // Returns the largest nontrivial factor of a number.
    // Returns 1 if number is prime.
    uInt largestFactor(uInt num);

    // Compute the totient of a number.
    uInt totient(uInt num);

    // Check whether a number is amicable.
    bool isAmicable(uInt num);

  private:
    // Expands d_max by factor 4 and d_primes by factor 2.
    void expand();
};

} // namespace euler

#endif
