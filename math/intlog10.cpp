#include "math.h"

namespace math {

// Returns the integer part of log10.
uInt intlog10(uInt num)
{
    int n = 0;
    while (num >= 10'000'000'000'000'000){n += 16; num /= 10'000'000'000'000'000;}
    if (num >= 100'000'000){n += 8; num /= 100'000'000;}
    if (num >= 10'000){n += 4; num /= 10'000;}
    if (num >= 100){n += 2; num /= 100;}
    if (num >= 10){++n; num /= 10;}
    return n;       
}

} // Namespace math.
