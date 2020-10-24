#include "numbersplit.h"
#include "../euler.h" // circular reference
#include <bitset>

// Yield the next set.
std::vector<size_t> euler::NumberSplit::yieldNext()
{
    ++d_count;
    
    d_set.clear(); 
    d_mem = firstNdigits(d_number, 1);

    std::bitset<64> mask = d_count; // good for up to 2**64
    for (size_t idx = 0; idx != d_length; ++idx)
    {
        if (mask[idx])
        {
            d_set.push_back(d_mem);
            d_mem = 0;
        }

        d_mem *= 10;
        d_mem += nthDigit(d_number, d_length - idx);

        if (idx == d_length - 1)
            d_set.push_back(d_mem);
    }

    return d_set;
}
