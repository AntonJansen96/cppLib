#include "../euler.h"
#include <cmath>

// Returns the first N digits from base^exp.
size_t firstNdigits(int base, int exp, int N)
{
    double num = exp * log10(base);
    num -= floor(num);
    num = std::pow(10, num);
    
    return static_cast<size_t>(std::floor(std::pow(10, N - 1) * num));
}
