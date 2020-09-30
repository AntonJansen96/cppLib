#include "../euler.h"

// Check whether num is a perfect number.
bool euler::isPerfect(size_t num)
{   
    if
    (
        num == 6 or
        num == 28 or 
        num == 496 or
        num == 8128 or
        num == 33550336 or
        num == 8589869056 or
        num == 137438691328 or
        num == 2305843008139952128 // next one is larger than size_t so stop.
    )
        return true;

    return false;
}
