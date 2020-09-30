#include "../euler.h"

namespace {

static const std::vector<size_t> power = 
{
    1, 10, 100, 1'000, 10'000, 100'000, 1'000'000, 10'000'000, 100'000'000,
    1'000'000'000, 10'000'000'000, 100'000'000'000, 1'000'000'000'000,
    10'000'000'000'000, 100'000'000'000'000, 1'000'000'000'000'000,
    10'000'000'000'000'000, 100'000'000'000'000'000, 
    1'000'000'000'000'000'000
};    

} // Namespace.

// Returns the first N digits from a number.
size_t euler::firstNdigits(size_t num, int N)
{
    while(num >= power[N])
        num /= 10;
    
    return num;    
}
