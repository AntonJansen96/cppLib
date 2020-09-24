#include "combinations.h"
#include <algorithm>

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
