#include "permutations.h"
#include "../math/math.h"
#include "../utility/utility.h"
#include <algorithm>

// Initialize Permutations object.
euler::Permutations::Permutations(std::vector<int> const &input, bool reverse)
    : d_someSet(input)
    , d_total(math::factorial(input.size()))
    , d_reverse(reverse)
{
    std::sort(d_someSet.begin(), d_someSet.end());

    if (not d_reverse)
        std::reverse(d_someSet.begin(), d_someSet.end());
}

// Yields the next permutation as a vector.
std::vector<int> euler::Permutations::yield()
{
    ++d_count;

    if (d_reverse)
        std::prev_permutation(d_someSet.begin(), d_someSet.end());
    else
        std::next_permutation(d_someSet.begin(), d_someSet.end());

    return d_someSet;
}

// Yield the next permutation as an integer.
// This is only possible when all elements are digits.
size_t euler::Permutations::yieldnumber()
{
    ++d_count;

    if (d_reverse)
        std::prev_permutation(d_someSet.begin(), d_someSet.end());
    else
        std::next_permutation(d_someSet.begin(), d_someSet.end());

    return utility::vec2num(d_someSet);
}

// Resets everything.
void euler::Permutations::reset()
{
    d_count = 0;
    std::sort(d_someSet.begin(), d_someSet.end());
    std::reverse(d_someSet.begin(), d_someSet.end());
}
