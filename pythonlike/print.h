#ifndef PRINT_H
#define PRINT_H

#include <iostream>

namespace pythonlike {

// Returns abstract container as a string.
template <typename Type>
std::string ctos(Type const &input)
{
    // Prevent segfaults when abstract container is empty.
    if (input.empty())
        return "[]";

    std::string output{"["};
    for (size_t idx = 0; idx != input.size(); ++idx)
    {
        if (idx == input.size() - 1)
            output += std::to_string(input[idx]);
        else
            output += std::to_string(input[idx]) + ", ";
    }
    return output + ']';

    // typename Type::const_iterator iter, end(input.end());

    // std::string output{"["};
    // for (iter = input.begin(); iter != end; ++iter)
    //     output += std::to_string(*iter) + ", ";

    // output.pop_back();  // Remove the last space
    // output.pop_back();  // Remove the last comma
    // return output + ']';
}

// Specialization: returns abstract container of strings as a string.
template <template <typename...> class Container>
std::string ctos(Container<std::string> const &input)
{
    // Prevent segfaults when abstract container is empty.
    if (input.empty())
        return "[]";

    std::string output{"["};
    for (size_t idx = 0; idx != input.size(); ++idx)
    {
        if (idx == input.size() - 1)
            output += input[idx];
        else
            output += input[idx] + ", ";
    }
    return output + ']';

    // std::string output{"["};
    // for (const auto& item : input)
    //     output += item + ", ";

    // output.pop_back();  // Remove the last space
    // output.pop_back();  // Remove the last comma
    // return output + ']';
}

// Base template for printing of primitive types.
template <typename Type>
void print(Type const &input)
{
    std::cout << input << '\n';
}

// Specialization for printing of the std::strings.
void print(std::string const &input)
{
    std::cout << input << '\n';
}

// Specialization for printing of abstract containers.
template <template <typename, typename...> class ContainerType, typename ValueType, typename... Args>
void print(const ContainerType<ValueType, Args...>& input)
{
    std::cout << ctos(input) << '\n';
}

// Specialization for std::string
template <template <typename, typename...> class ContainerType, typename... Args>
void print(const ContainerType<std::string, Args...>& input)
{
    std::cout << ctos(input) << '\n';
}

// Print to terminal.
template <typename T, typename... Args>
void print(T first, Args... args)
{
    // std::cout << first << ' ';
    print(args...);  // Recursive call with remaining arguments
}

} // namespace

#endif
