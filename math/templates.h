#ifndef CPPLIB_MATH_TEMPLATES_H
#define CPPLIB_MATH_TEMPLATES_H

#include <cmath>
#include <numeric>

namespace math
{

// Mean of values in abstract container.
template <typename Container> double mean(Container const &array)
{
    auto sum = std::accumulate(array.begin(), array.end(), 0);
    auto len = static_cast<double>(array.size());

    return sum / len;
}

// Standard deviation of values in abstract container.
template <typename Container> double sdev(Container const &array)
{
    auto Mean = mean(array);
    auto len = static_cast<double>(array.size());

    auto sq_sum = std::inner_product(array.begin(), array.end(), array.begin(), 0.0,
                                     std::plus<>(), [Mean](auto x, auto y)
                                     { return (x - Mean) * (y - Mean); });

    return std::sqrt(sq_sum / len);
}

} // namespace math.

#endif
