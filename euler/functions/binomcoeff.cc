#include "../euler.h"

namespace euler {

// Returns binomial coefficient of N and n.
double binomCoeff(int N, int n)
{
    return factorial(N) / (factorial(n) * factorial(N - n));
}

} // Namespace.
