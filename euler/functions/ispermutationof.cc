#include "../euler.h"

namespace {

size_t fingerPrint(size_t num)
{
    size_t digit, result = 0;
    while (num > 0)
    {
        digit = num % 10;
        num /= 10;

        result += 1ULL << (5 * digit);
    }

    return result;
}

} // Namespace.

// Check whether the number a is a digit permutation of number b.
bool euler::isPermutationOf(size_t a, size_t b)
{
    return (fingerPrint(a) == fingerPrint(b)) ? true : false;
}
