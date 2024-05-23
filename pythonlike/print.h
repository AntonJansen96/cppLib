#ifndef CPPLIB_PYTHONLIKE_PRINT_H
#define CPPLIB_PYTHONLIKE_PRINT_H

// clang-format off
#ifdef DEBUG
#define LOG(x) std::clog << "DEBUG: " << x << '\n'
#else
#define LOG(x) do {} while (0)
#endif
// clang-format on

#include <cmath>
#include <concepts>
#include <generator>
#include <iomanip>
#include <iostream>

namespace // Anonymous namespace for helper functions.
{

// Case 1: no print() arguments specified.

inline void doprint()
{
    LOG("case 1 (no arguments specified) was called");
}

// Case 2: print() base case.

template <typename Type> void doprint(Type const &input, bool fromC = false)
{
    LOG("case 2 (print base case) was called");
    if constexpr (std::is_floating_point_v<Type>)
    {
        if (std::floor(input) == input)
            std::cout << std::fixed << std::setprecision(1) << input;
        else
            std::cout << std::defaultfloat << std::setprecision(6) << input;
    }
    else
        std::cout << input;
}

// Case 3: print() arguments of type bool (for std::boolalpha).

inline void doprint(bool input, bool fromC = false)
{
    LOG("case 3 (print args of type bool) was called");

    std::cout << std::boolalpha << input;
}

// Case 4: print() arguments of type std::string, char, and char*.
// Treat separately because in containers we want to print these args as 'arg'.

template <typename Type>
concept StringChar = std::is_same_v<Type, std::string> || std::is_same_v<Type, char> ||
                     std::is_same_v<Type, const char *>;

template <StringChar Type> void doprint(Type const &input, bool fromC = false)
{
    LOG("case 4 (print args of type string, char, char*) was called");

    if (fromC)
        std::cout << "'" << input << "'";
    else
        std::cout << input;
}

// Case 5: print() arguments of the types derived from std::ostream.

template <typename Type>
concept Stream = std::is_base_of<std::ostream, Type>::value;

template <Stream Type> void doprint(Type *input, bool fromC = false)
{
    LOG("case 5 (print args of types derived from std::ostream) was called");

    std::cout << (*input).str();
}

// Case 6: print() Container arguments, but not std::string.

template <typename Type>
concept Container = requires(Type const &input) {
    { input.begin() } -> std::same_as<typename Type::const_iterator>;
    { input.end() } -> std::same_as<typename Type::const_iterator>;
    { input.empty() } -> std::same_as<bool>;
} && !std::same_as<Type, std::string>;

template <Container Type> void doprint(Type const &input, bool fromC = false)
{
    LOG("case 6 (print Container types) was called");

    std::cout << '[';

    typename Type::const_iterator iter, end(input.end());
    // Do not use a range-based for-loop here as std::next() is more universal.
    for (iter = input.begin(); iter != end; ++iter)
    {
        doprint(*iter, true);
        if (std::next(iter) != input.end())
            std::cout << ", ";
    }

    std::cout << "]";
}

// Case 7: print() arguments of type pair (this is straightforward).

template <typename Type1, typename Type2>
void doprint(std::pair<Type1, Type2> const &input, bool fromC = false)
{
    LOG("case 7 (print args of type pair) was called");

    std::cout << '(';
    doprint(input.first, true);
    std::cout << ", ";
    doprint(input.second, true);
    std::cout << ')';
}

// Case 8: print() arguments of type tuple (this is more complex).

template <typename... Args>
void doprint(std::tuple<Args...> const &input, bool fromC = false)
{
    LOG("case 8 (print args of type tuple) was called");

    std::cout << '(';
    std::apply(
        [&](auto const &...args)
        {
            size_t n = 0;
            ((doprint(args, true), std::cout << (++n != sizeof...(args) ? ", " : "")),
             ...);
        },
        input);
    std::cout << ')';
}

// Case 9: print() arguments of type std::generator (C++23).
template <typename Type> void doprint(std::generator<Type> &input)
{
    LOG("case 9 (print args of type std::generator (C++23)) was called");

    bool start = true;
    std::cout << '[';
    for (auto const &val : input)
    {
        if (!start) // if-else statement is to prevent writing a comma at the end.
            std::cout << ", ";
        else
            start = false;
        doprint(val, true);
    }
    std::cout << ']';
}

// Main variadic template function.
template <typename Type, typename... Args> void doprint(Type first, Args... args)
{
    doprint(first);
    doprint(' ');
    doprint(args...);
}

} // anonymous namespace.

namespace pythonlike
{

// print args to terminal.
template <typename... Args> void print(Args... args) noexcept
// This is a wrapper for the main variadic template function.
// We wrap so we can insert newline character after doprint finishes.
{
    doprint(args...);
    std::cout << '\n';
}

} // namespace pythonlike.

#endif
