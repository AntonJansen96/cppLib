#include "math.h"

namespace math {

// Returns factorial of number.
uInt factorial(uInt num)
{
    return (num > 1) ? num * factorial(num - 1) : 1;
}

} // Namespace math.
