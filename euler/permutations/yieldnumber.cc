#include "permutations.h"
#include <algorithm>

// Yield the next permutation as an integer.
// This is only possible when all elements are digits.
size_t euler::Permutations::yieldnumber()
{
    ++d_count;
    
    if (d_reverse)
        std::prev_permutation(d_someSet.begin(), d_someSet.end());
    else
        std::next_permutation(d_someSet.begin(), d_someSet.end());
    
    return vector2number(d_someSet);
}
