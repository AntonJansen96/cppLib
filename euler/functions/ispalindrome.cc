#include "../euler.h"

// Check whether a number is a palindrome.
bool euler::isPalindrome(size_t num)
{
    size_t tmp = num, invnum = 0;

    while (tmp)
    {
        invnum = invnum * 10 + (tmp % 10);
        tmp /= 10;
    }

    return invnum == num ? true : false;
}
