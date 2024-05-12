#ifndef CPPLIB_PYTHONLIKE_H
#define CPPLIB_PYTHONLIKE_H

#include "fstring.h"
#include "print.h"
#include "slice.h"

#include <algorithm> // for std::sort
#include <cmath>     // for std::round, std::pow
#include <numeric>   // for std::accumulate
#include <vector>    // for std::vector

namespace pythonlike
{

// Returns sum of elements in abstract container.
template <typename Type> typename Type::value_type sum(Type const &input)
{
    return std::accumulate(input.begin(), input.end(), typename Type::value_type());
}

// Return the largest element in the abstract container.
template <typename Type> typename Type::value_type max(Type const &input)
{
    if (input.empty())
        return 0;

    typename Type::const_iterator iter, end(input.end());
    typename Type::value_type largest = *input.begin();

    for (iter = input.begin(); iter != end; ++iter)
        if (*iter > largest)
            largest = *iter;

    return largest;
}

// Return the smallest element in the abstract container.
template <typename Type> typename Type::value_type min(Type const &input)
{
    if (input.empty())
        return 0;

    typename Type::const_iterator iter, end(input.end());
    typename Type::value_type smallest = *input.begin();

    for (iter = input.begin(); iter != end; ++iter)
        if (*iter < smallest)
            smallest = *iter;

    return smallest;
}

// Sort elements in abstract container. Returns sorted array.
// Note: sorting is not done in-place.
template <typename Type> Type sorted(Type input)
{
    std::sort(input.begin(), input.end());
    return input;
}

// Sort elements in abstract container in-place.
template <typename Type> void isorted(Type &input)
{
    std::sort(input.begin(), input.end());
}

// Reverse elements in abstract container. Returns reversed array.
template <typename Type> Type reverse(Type input)
{
    std::reverse(input.begin(), input.end());
    return input;
}

// Reverse elements in abstract container in-place.
template <typename Type> void ireverse(Type &input)
{
    std::reverse(input.begin(), input.end());
}

// Round floating point numbers to a specific number of decimal places.
template <typename Type> Type round(Type number, int precision = 3)
{
    Type scale = 1;
    for ([[maybe_unused]] auto _ : range(precision))
        scale *= 10;

    return std::round(number * scale) / scale;
}

} // namespace pythonlike.

#endif // PYTHONLIKE_H
