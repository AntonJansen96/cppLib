#include "../euler.h"
#include <cmath>

// Check whether num is a square.
bool euler::isSquare(size_t num)
{
    size_t h = num & 0xF;           // Last hexadecimal "digit".
    
    if (h > 9)
        return false;               // Return immediately in 6/16 cases.

    if (h != 2 && h != 3 && h != 5 && h != 6 && h != 7 && h != 8)
    {
        size_t root = std::floor(std::sqrt(num) + 0.5);
        return (root * root == num);  // Take square root if you must.
    }
    
    return false;
}
