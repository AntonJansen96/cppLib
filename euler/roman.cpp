#include <map>
#include <string>

namespace euler
{

static std::string const M[] = {"", "M", "MM", "MMM", "MMMM"};
static std::string const H[] = {"",  "C",  "CC",  "CCC",  "CD",
                                "D", "DC", "DCC", "DCCC", "CM"};
static std::string const T[] = {"",  "X",  "XX",  "XXX",  "XL",
                                "L", "LX", "LXX", "LXXX", "XC"};
static std::string const O[] = {"",  "I",  "II",  "III",  "IV",
                                "V", "VI", "VII", "VIII", "IX"};

// Converts a decimal number to a Roman numeral.
std::string dec2roman(int dec)
{
    return M[dec / 1000] + H[dec % 1000 / 100] + T[dec % 100 / 10] + O[dec % 10];
}

static std::map<char, int> dict = {{'M', 1000}, {'D', 500}, {'C', 100}, {'L', 50},
                                   {'X', 10},   {'V', 5},   {'I', 1}};

// Converts a Roman numeral to a decimal number.
int roman2dec(std::string const &roman)
{
    size_t decimal = 0;

    for (size_t idx = 0; idx < roman.length(); ++idx)
    {
        if (idx + 1 < roman.length())
        {
            if (dict[roman[idx]] >= dict[roman[idx + 1]])
                decimal += dict[roman[idx]];
            else
            {
                decimal += (dict[roman[idx + 1]] - dict[roman[idx]]);
                ++idx;
            }
        }
        else
            decimal += dict[roman[idx]];
    }
    return decimal;
}

} // namespace euler.
