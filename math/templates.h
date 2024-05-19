#ifndef CPPLIB_MATH_TEMPLATES_H
#define CPPLIB_MATH_TEMPLATES_H

#include <algorithm>
#include <cmath>
#include <numeric>
#include <ranges>

namespace math
{

// Mean of values in abstract container.
template <typename Container> double mean(Container const &array)
{
    if (array.empty()) // Edge case for empty container.
        return 0.0;

    auto sum = std::accumulate(array.begin(), array.end(), 0);
    auto len = static_cast<double>(array.size());

    return sum / len;
}

// Standard deviation of values in abstract container.
template <typename Container> double sdev(Container const &array)
{
    if (array.empty()) // Edge case for empty container.
        return 0.0;

    auto Mean = mean(array);
    auto len = static_cast<double>(array.size());

    auto sq_sum = std::inner_product(array.begin(), array.end(), array.begin(), 0.0,
                                     std::plus<>(), [Mean](auto x, auto y)
                                     { return (x - Mean) * (y - Mean); });

    return std::sqrt(sq_sum / len);
}

// Median of values in abstract container.
template <typename Container> double median(Container &array)
{
    // Source: Evolution of a Median Algorithm in C++ - Pete Isensee - CppCon 2023.
    using namespace std::ranges;

    if (array.empty()) // edge case
        return 0.0;

    auto const mid = std::begin(array) + (std::size(array) / 2);
    std::nth_element(std::begin(array), mid, std::end(array));
    if (std::size(array) % 2) // odd
        return static_cast<double>(*mid);

    const subrange lowerHalf{std::begin(array), mid}; // even
    auto const midNeighbor = max_element(lowerHalf);
    return std::midpoint<double>(*midNeighbor, *mid);
}

} // namespace math.

#endif
