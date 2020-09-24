#include "permutations.h"
#include <algorithm>

// Initialize Permutations object.
euler::Permutations::Permutations(std::vector<int> const &input, bool reverse)
:
    d_someSet(input),
    d_total(factorial(input.size())),
    d_reverse(reverse)
{
    std::sort(d_someSet.begin(), d_someSet.end());

    if (not d_reverse)
        std::reverse(d_someSet.begin(), d_someSet.end());
}
