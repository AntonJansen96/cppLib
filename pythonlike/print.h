#ifndef PRINT_H
#define PRINT_H

#include <iostream>

namespace pythonlike {

// Return abstract container as a string.
template <typename Type>
std::string ctos(Type const &input)
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

// Specialization for abstract containers containing strings.
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

// Base template for printing of primitive types.
template <typename Type>
void _doprint(Type const &input)
{
    std::cout << input << ' ';
}

// Specialization for printing of the std::string type.
void _doprint(std::string const &input)
{
    std::cout << input << ' ';
}

// Specialization for printing of abstract containers.
template <template <typename, typename...> class ContainerType, typename ValueType, typename... Args>
void _doprint(ContainerType<ValueType, Args...> const &input)
{
    std::cout << pythonlike::ctos(input) << ' ';
}

// Specialization to handle when nothing is specified.
void _doprint()
{}

// Variadic template. Main thing that gets executed.
template <typename T, typename... Args>
void _doprint(T first, Args... args)
{
    _doprint(first);
    _doprint(args...);
}

// This is a wrapper for the variadic template function.
// We do this so we can print a newline after variadic finishes.

// Print arguments to terminal.
template <typename... Args>
void print(Args... args)
{
    _doprint(args...);
    std::cout << std::endl;
}

} // namespace pythonlike.

#endif
