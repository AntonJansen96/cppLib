#include "math.h"
#include <cmath>

namespace math
{

// Integer part of the square root. Returns 0 for negative numbers.
uInt isqrt(sInt n)
{
    return n < 0 ? 0 : static_cast<uInt>(std::sqrt(n));
}

} // namespace math
