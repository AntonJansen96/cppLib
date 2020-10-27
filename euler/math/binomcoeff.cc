#include "math.h"

// Returns binomial coefficient of N and n.
double euler::math::binomCoeff(int N, int n)
{
    return factorial(N) / (factorial(n) * factorial(N - n));
}
