#include "combinations.h"
#include <algorithm>

// Initialize combinations object.
euler::Combinations::Combinations(std::vector<int> const &input, size_t k, bool reverse)
:
    d_someSet(input),
    d_mask(k, true),
    d_masksize(input.size()),
    d_total(binomCoeff(input.size(), k)),
    d_k(k),
    d_reverse(reverse)
{
    std::sort(d_someSet.begin(), d_someSet.end());

    if (d_reverse)
        std::reverse(d_someSet.begin(), d_someSet.end());

    d_mask.resize(input.size(), false);
}
