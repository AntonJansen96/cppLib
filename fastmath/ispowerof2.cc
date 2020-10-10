#include "fastmath.h"

// Check whether num is a power of 2.
bool fastMath::isPowerOf2(size_t num)
{
    return num && !(num & (num - 1));
}
