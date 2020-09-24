#include "../euler.h"

// Returns binomial coefficient of N and n.
double euler::binomCoeff(size_t N, size_t n)
{
    return euler::factorial(N) / (euler::factorial(n) * euler::factorial(N - n));
}
