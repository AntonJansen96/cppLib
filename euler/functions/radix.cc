#include "../euler.h"

// Converts a decimal number to a specified radix.
std::string euler::radix(size_t value, size_t radix)
{
    std::string accumulate;                 // Stores the converted number.

    do
    {
        size_t ch = value % radix;          // Get the last digit.
        value /= radix;                     // Cut off the last digit.

        ch += ch < 10 ? '0' : 'a' - 10;     // Convert ch to char.

        accumulate.insert(0, 1, ch);        // Insert digit before other digit.
    }
    while (value);

    return accumulate;
}
