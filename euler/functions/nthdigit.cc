#include "../euler.h"

// Returns the nth digit of a number (starting at least significant digit)
int euler::nthDigit(size_t num, int n)
{
    while (--n > 0)
        num /= 10;
        
    return num % 10;
}
