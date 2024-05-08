#include "math.h"

namespace math
{

// Returns factorial of number (0 if 64-bit overflow).
uInt factorial(uInt num)
{
    if (num > 20) // 64-bit overflow.
        return 0;

    return (num > 1) ? num * factorial(num - 1) : 1;
}

} // Namespace math.
