#ifndef CPPLIB_PYTHONLIKE_PRINT_H
#define CPPLIB_PYTHONLIKE_PRINT_H

#include <iostream>
#include <sstream>

namespace pythonlike
{

// Return abstract container as a string.
template <typename Type> std::string ctos(Type const &input)
{
    if (input.empty())
        return "[]";

    typename Type::const_iterator iter, end(input.end());

    std::string output{"["};
    for (iter = input.begin(); iter != end; ++iter)
    {
        output += std::to_string(*iter);
        if (std::next(iter) != input.end())
            output += ", ";
    }
    return output + ']';
}

// Specialization for abstract containers containing std::strings.
template <template <typename...> class Container>
std::string ctos(Container<std::string> const &input)
{
    if (input.empty())
        return "[]";

    std::string output{"["};
    for (auto iter = input.begin(); iter != input.end(); ++iter)
    {
        output += "'" + *iter + "'";
        if (std::next(iter) != input.end())
            output += ", ";
    }
    return output + ']';
}

// Base template for printing.
// Will work for primitive types and all objects with an overloaded << operator.
template <typename Type> void _doprint(Type const &input)
{
    std::cout << input << ' ';
}

// Specialization for printing of the bool type.
// We have a specialization so that we can print true/false instead of 1/0.
// Note: not a template, inline to avoid symbol duplication problems.
// Alternatively, we can put this in a .cpp file.
inline void _doprint(bool input)
{
    std::cout << std::boolalpha << input << ' ';
}

// Specialization for printing of the std::string type.
// Note: not a template, inline to avoid symbol duplication problems.
// Alternatively, we can put this in a .cpp file.
inline void _doprint(std::string const &input)
{
    std::cout << input << ' ';
}

// Specialization for printing of abstract containers.
template <template <typename, typename...> class ContainerType, typename ValueType,
          typename... Args>
void _doprint(ContainerType<ValueType, Args...> const &input)
{
    std::cout << pythonlike::ctos(input) << ' ';
}

// Specialization for printing of nested containers.
template <template <typename, typename...> class OuterContainerType,
          template <typename, typename...> class InnerContainerType, typename ValueType,
          typename... Args>
void _doprint(OuterContainerType<InnerContainerType<ValueType, Args...>> const &input)
{
    for (const auto &innerContainer : input)
    {
        _doprint(innerContainer);
        std::cout << '\n';
    }
}

// Specialization to handle when nothing is specified.
// Note: not a template, inline to avoid symbol duplication problems.
// Alternatively, we can put this in a .cpp file.
inline void _doprint()
{
}

// Variadic template. Main thing that gets executed.
template <typename T, typename... Args> void _doprint(T first, Args... args)
{
    _doprint(first);
    _doprint(args...);
}

// This is a wrapper for the variadic template function.
// We do this so we can print a newline after variadic finishes.

// Print arguments to terminal.
// Works for primitive types and all objects with an overloaded << operator.
// Also works for abstract containers containing primitive types and std::strings.
template <typename... Args> void print(Args... args)
{
    _doprint(args...);
    std::cout << std::endl;
}

namespace
{
// Helper function for the variadic template fs function.
template <typename Type> std::string to_string(Type value)
{
    std::ostringstream os;
    os << value;
    return os.str();
}
} // anonymous namespace.

// Create a Python-style f-string.
// Use: fs("{} {}", "hello", "world!").
template <typename... Args> std::string fs(std::string const &input, Args... args)
{
    std::string output{input};
    std::string argStrings[] = {to_string(args)...};

    for (auto const &arg : argStrings)
    {
        size_t pos = output.find_first_of('{');
        output.replace(pos, 2, arg);
    }

    return output;
}

} // namespace pythonlike.

#endif
