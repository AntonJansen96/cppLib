#ifndef PYTHONLIKE_H
#define PYTHONLIKE_H

#include "print.h"
#include "slice.h"

#include <vector>       // for std::vector
#include <numeric>      // for std::accumulate
#include <algorithm>    // for std::sort

namespace pythonlike {

// Returns sum of elements in abstract container.
template <typename Type>
typename Type::value_type sum(Type const &input)
{
    return std::accumulate
    (
        input.begin(), input.end(), typename Type::value_type()
    );
}

// Return the largest element in the abstract container.
template <typename Type>
typename Type::value_type max(Type const &input)
{
    typename Type::const_iterator iter, end(input.end());
    typename Type::value_type largest = *input.begin();

    for (iter = input.begin(); iter != end; ++iter)
        if (*iter > largest)
            largest = *iter;
    
    return largest;
}

// Return the smallest element in the abstract container.
template <typename Type>
typename Type::value_type min(Type const &input)
{
    typename Type::const_iterator iter, end(input.end());
    typename Type::value_type smallest = *input.begin();

    for (iter = input.begin(); iter != end; ++iter)
        if (*iter < smallest)
            smallest = *iter;
    
    return smallest;
}

// Sort elements in abstract container. Returns sorted array.
// Note: sorting is not done in-place.
template <typename Type>
Type sorted(Type input)
{
    std::sort(input.begin(), input.end());
    return input;
}

// Sort elements in abstract container in-place.
template <typename Type>
void isorted(Type &input)
{
    std::sort(input.begin(), input.end());
}

} // namespace pythonlike.

#endif // PYTHONLIKE_H
