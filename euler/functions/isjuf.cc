#include "../euler.h"

// Checks whether a number is juf.
bool euler::isJuf(size_t num)
{
    return
    (
        num % 7 == 0
        ||
        std::to_string(num).find('7') != std::string::npos
        ||
        (euler::isPalindrome(num) && num > 10)
    )
        ? true : false;
}
