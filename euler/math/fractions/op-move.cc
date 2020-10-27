#include "fractions.h"
#include <utility>

namespace euler::math {

// Move-assignment operator.
Fraction &Fraction::operator=(Fraction &&other)
{
    std::swap(d_num, other.d_num);
    std::swap(d_den, other.d_den);

    return *this;
}

} // Namespace.
