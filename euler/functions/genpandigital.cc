#include "../euler.h"

// Generate all numbers that are a to b pandigital.
std::vector<size_t> euler::genPandigital(size_t a, size_t b)
{
    std::vector<int> digits;
    for (size_t digit = a; digit <= b; ++digit)
        digits.push_back(digit);

    Permutations perm(digits);

    std::vector<size_t> pandigitals;
    while (not perm.done())
    {
        size_t num = perm.yieldnumber();

        if (numDigits(num) == b - a + 1)
            pandigitals.push_back(num);
    }
        
    return pandigitals;
}
