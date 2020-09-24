#include "combinations.h"
#include <algorithm>

// Resets everything.
void euler::Combinations::reset()
{
    d_count = 0;
    std::sort(d_mask.begin(), d_mask.end());
    std::reverse(d_mask.begin(), d_mask.end());            
}
