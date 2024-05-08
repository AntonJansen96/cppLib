#include "combinations.h"
#include "../math/math.h"

#include <algorithm>

// Initialize combinations object.
euler::Combinations::Combinations(std::vector<int> const &input, size_t k, bool reverse)
:
    d_someSet(input),
    d_mask(k, true),
    d_masksize(input.size()),
    d_total(math::binom(input.size(), k)),
    d_k(k),
    d_reverse(reverse)
{
    std::sort(d_someSet.begin(), d_someSet.end());

    if (d_reverse)
        std::reverse(d_someSet.begin(), d_someSet.end());

    d_mask.resize(input.size(), false);
}

// Yields the next combination.
std::vector<int> euler::Combinations::yield()
{
    ++d_count;

    d_comb.clear();
    for (size_t idx = 0; idx != d_masksize; ++idx)
        if (d_mask[idx])
            d_comb.push_back(d_someSet[idx]);

    std::prev_permutation(d_mask.begin(), d_mask.end());

    return d_comb;
}

// Yields the next combination.
size_t euler::Combinations::yieldnumber()
{
    ++d_count;

    d_comb.clear();
    for (size_t idx = 0; idx != d_masksize; ++idx)
        if (d_mask[idx])
            d_comb.push_back(d_someSet[idx]);

    std::prev_permutation(d_mask.begin(), d_mask.end());

    return vector2number(d_comb);
}

// Resets everything.
void euler::Combinations::reset()
{
    d_count = 0;
    std::sort(d_mask.begin(), d_mask.end());
    std::reverse(d_mask.begin(), d_mask.end());            
}

// Transforms a vector of digits into an integer.
size_t euler::Combinations::vector2number(std::vector<int> const &input)
{
    size_t number = 0;
    for (auto digit : input)
        number = number * 10 + digit;

    return number;
}
