#include "fractions.h"
#include <iostream>

namespace euler::math {

// Insert Fraction (r-value) into stream.
std::ostream &operator<<(std::ostream &out, Fraction &&obj)
{
    return out << obj.num() << '/' << obj.denom();
}

} // Namespace.
