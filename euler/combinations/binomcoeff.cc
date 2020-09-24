#include "combinations.h"

// Private function to compute binomial coefficient.
double euler::Combinations::binomCoeff(size_t N, size_t n) const
{
    return factorial(N) / (factorial(n) * factorial(N - n));
}
