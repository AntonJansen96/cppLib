#include "../euler.h"
#include <algorithm>

namespace {

// Data so make static so we don't define it every time function is called.
static std::vector<size_t> const pNums = 
{   
    6, 28, 496, 8128, 33550336, 8589869056, 137438691328, 
    2305843008139952128
};

}

bool euler::isPerfect(size_t num)
{   
    return
    (
        std::find(pNums.begin(), pNums.end(), num) != pNums.end()
        ?
        true : false
    );
}
