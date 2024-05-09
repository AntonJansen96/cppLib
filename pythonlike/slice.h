#ifndef CPPLIB_PYTHONLIKE_SLICE_H
#define CPPLIB_PYTHONLIKE_SLICE_H

#include <algorithm>
#include <string>
#include <vector>
#include <array>
#include <ranges>

namespace pythonlike {

// Slice char* strings. Returns sliced string as a new char*.
// Note: not a template, inline to avoid symbol duplication problems.
// Alternatively, we can put this in a .cpp file.
inline char* slice(const char* string, size_t m, size_t n)
{
    size_t len = n - m;
    char* result = new char[len + 1];
    std::copy(string + m, string + n, result);
    result[len] = '\0';
    return result;
}

// Slice std::vector, std::deque, std::list, std::forward_list.
// Returns the sliced container as a copy.
template <typename Container>
auto slice(Container const &container, size_t m, size_t n)
{
    auto a = std::next(container.begin(), m);
    auto b = std::next(container.begin(), n);

    return Container(a, b);
}

// Specialization to slice std::strings. Return sliced string as a new std::string.
// Note: not a template, inline to avoid symbol duplication problems.
// Alternatively, we can put this in a .cpp file.
inline std::string slice(std::string const &string, size_t m, size_t n)
{
    return string.substr(m, n - m);
}

// Specialization to slice a std::array. Returns sliced copy as a std::vector.
template <typename Type, std::size_t N>
std::vector<Type> slice(std::array<Type, N> const &container, size_t m, size_t n)
{
    auto a = std::next(container.begin(), m);
    auto b = std::next(container.begin(), n);

    return std::vector<Type>(a, b);
}

// view(container, m, n)
// Returns a view of the sliced container.
// A view is way to access the container without copying it.
// This is helpful for range-based for loops.
template <typename Container>
auto view(Container const &container, size_t m, size_t n)
{
    auto a = std::next(container.begin(), m);
    auto b = std::next(container.begin(), n);

    return std::ranges::subrange(a, b);
}

// Generate a range of numbers for use in range-based for loops.
// Note: not a template, inline to avoid symbol duplication problems.
// Alternatively, we can put this in a .cpp file.
inline auto range(long start, long stop = 0, long step = 1)
{
    if (stop == 0)
    {
        stop = start;
        start = 0;
    }

    if (step == 0)
    {
        std::cerr << "range() : step cannot be zero, setting step to 1." << std::endl;
        step = 1;
    }

    if ((step > 0 && start >= stop) || (step < 0 && start <= stop))
    {
        std::cerr << "range() : invalid range, returning empty range." << std::endl;
        start = 0;
        stop = 0;
    }

    return std::ranges::views::iota(0, step > 0 ? (stop - start + step - 1) / step : (start - stop - step - 1) / -step)
           | std::ranges::views::transform([=](long i) { return start + i * step; });
}

} // namespace pythonlike.

#endif // SLICE_H
