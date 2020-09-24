#include "../euler.h"
#include <cmath>

// Return the number of digits of a number.
size_t euler::numDigits(double num)
{
    return 1 + log10(num);
}
