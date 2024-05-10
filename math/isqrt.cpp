#include "math.h"
#include <cmath>

namespace math
{

// Integer part of the square root.
uInt isqrt(uInt n)
{
    return static_cast<uInt>(std::sqrt(n));
}

} // namespace math
