#include "fractions.h"
#include <iostream>

namespace euler::math {

// Insert Fraction (l-value) into stream.
std::ostream &operator<<(std::ostream &out, Fraction &obj)
{
    return out << obj.num() << '/' << obj.denom();
}

} // Namespace.
