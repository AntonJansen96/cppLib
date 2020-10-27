#include "../euler.h"

// Returns the number of digits of a number.
int euler::numDigits(size_t num)
{
    return math::intlog10(num) + 1;
}
