#include "combinations.h"
#include "../math/math.h"
#include "../utility/utility.h"

#include <algorithm>

namespace euler
{

// Initialize combinations object.
Combinations::Combinations(std::vector<uInt> const &input, uInt k, bool reverse)
    : d_someSet(input)
    , d_mask(k, true)
    , d_masksize(input.size())
    , d_total(math::binom(input.size(), k))
    , d_k(k)
    , d_reverse(reverse)
{
    std::sort(d_someSet.begin(), d_someSet.end());

    if (d_reverse)
        std::reverse(d_someSet.begin(), d_someSet.end());

    d_mask.resize(input.size(), false);
}

// Yields the next combination.
std::vector<uInt> Combinations::yield()
{
    ++d_count;

    d_comb.clear();
    for (uInt idx = 0; idx != d_masksize; ++idx)
        if (d_mask[idx])
            d_comb.push_back(d_someSet[idx]);

    std::prev_permutation(d_mask.begin(), d_mask.end());

    return d_comb;
}

// Yields the next combination.
uInt Combinations::yieldnumber()
{
    ++d_count;

    d_comb.clear();
    for (uInt idx = 0; idx != d_masksize; ++idx)
        if (d_mask[idx])
            d_comb.push_back(d_someSet[idx]);

    std::prev_permutation(d_mask.begin(), d_mask.end());

    return utility::vec2num(d_comb);
}

// Resets everything.
void Combinations::reset()
{
    d_count = 0;
    std::sort(d_mask.begin(), d_mask.end());
    std::reverse(d_mask.begin(), d_mask.end());
}

} // namespace euler
