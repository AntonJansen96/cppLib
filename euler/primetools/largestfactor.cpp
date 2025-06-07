#include "primetools.h"

namespace euler
{

// Returns the largest nontrivial factor of a number.
// Returns 1 if number is prime.
uInt Primetools::largestFactor(uInt num)
{
    return (num < 2) ? 0 : num / this->factorPrimeSingle(num)[0];
}

} // namespace euler
