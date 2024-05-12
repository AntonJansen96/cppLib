#include "numbersplit.h"
#include "../euler.h"

#include <bitset>

namespace euler
{

// Constructor
NumberSplit::NumberSplit(uInt number)
    : d_number(number)
    , d_length(numDigits(number) - 1) // hekje paaltje met komma's
    , d_total(1 << d_length)          // 2**d_length
{
}

// Yield the next set.
std::vector<uInt> NumberSplit::yieldNext()
{
    ++d_count;

    d_set.clear();
    d_mem = firstNdigits(d_number, 1);

    std::bitset<64> mask = d_count; // good for up to 2**64
    for (uInt idx = 0; idx != d_length; ++idx)
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

} // namespace euler
