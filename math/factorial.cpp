#include "math.h"

namespace math
{

// Returns factorial of number.
double factorial(uInt num)
{
    double result = 1.0;
    for (size_t i = 2; i <= num; ++i)
        result *= i;
    return result;
}

} // Namespace math.
