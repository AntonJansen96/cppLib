#include "combinations.h"

namespace {

double factorial(double num)
{
    if (num > 1)
        return num * factorial(num - 1);
    else
        return 1;
}

} // Namespace.

// Private function to compute binomial coefficient.
double euler::Combinations::binomCoeff(size_t N, size_t n) const
{
    return factorial(N) / (factorial(n) * factorial(N - n));
}
