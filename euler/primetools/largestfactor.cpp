#include "primetools.h"

// Returns the largest nontrivial factor of a number.
// Returns 1 if number is prime.
size_t euler::Primetools::largestFactor(size_t num)
{
    return (num < 2) ? 0 : num / this->factorPrimeSingle(num)[0];
}
