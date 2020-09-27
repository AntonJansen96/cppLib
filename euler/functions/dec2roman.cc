#include "../euler.h"

namespace {

static std::string const M[] = {"", "M", "MM", "MMM", "MMMM"};
static std::string const H[] = {"", "C", "CC", "CCC", "CD", "D", "DC", "DCC", "DCCC", "CM"};
static std::string const T[] = {"", "X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "XC"};
static std::string const O[] = {"", "I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX"};

} // End of namespace.

// Converts a decimal number to a Roman numeral.
std::string euler::dec2roman(int dec)
{
    return M[dec / 1000] + H[dec % 1000 / 100] + T[dec % 100 / 10] + O[dec % 10];
}
