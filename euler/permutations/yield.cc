#include "permutations.h"
#include <algorithm>

// Yields the next permutation as a vector.
std::vector<int> euler::Permutations::yield()
{
    ++d_count;
    
    if (d_reverse)
        std::prev_permutation(d_someSet.begin(), d_someSet.end());
    else
        std::next_permutation(d_someSet.begin(), d_someSet.end());
    
    return d_someSet;
}
