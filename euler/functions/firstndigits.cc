#include "../euler.h"
#include <cmath>

// Returns the first N digits from base^exp.
size_t firstNdigits(size_t base, size_t exp, size_t N)
{
    double num = exp * log10(base);
    num -= floor(num);
    num = pow(10, num);
    
    return floor(pow(10, N - 1) * num);
}
