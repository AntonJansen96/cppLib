#ifndef CPPLIB_PYTHONLIKE_FSTRING_H
#define CPPLIB_PYTHONLIKE_FSTRING_H

#include <sstream>

namespace
{

// Helper function for the variadic template fs function.
template <typename Type> std::string _to_string(Type value)
{
    std::ostringstream os;
    os << value;
    return os.str();
}

} // anonymous namespace.

namespace pythonlike
{

// Create a Python-style f-string.
// Use: fs("{} {}", "hello", "world!").
template <typename... Args> std::string fs(std::string const &input, Args... args)
{
    std::string output{input};
    std::string argStrings[] = {_to_string(args)...};

    for (auto const &arg : argStrings)
    {
        size_t pos = output.find_first_of('{');

        if (pos == std::string::npos) // if not found, pos will be
            break;                    // out of range, so we break.

        output.replace(pos, 2, arg);
    }

    return output;
}

} // namespace pythonlike.

#endif
