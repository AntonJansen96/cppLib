#include "../euler.h"
#include <map>

namespace {

static std::map<char, int> dict =
{ 
    {'M', 1000},
    {'D', 500},
    {'C', 100},
    {'L', 50},
    {'X', 10},
    {'V', 5},
    {'I', 1}
};

} // Namespace.

// Converts a Roman numeral to a decimal number.
int euler::roman2dec(std::string const &roman)
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
