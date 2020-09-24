#include "permutations.h"
#include <algorithm>

// Resets everything.
void euler::Permutations::reset()
{
    d_count = 0;
    std::sort(d_someSet.begin(), d_someSet.end());
    std::reverse(d_someSet.begin(), d_someSet.end());            
}
