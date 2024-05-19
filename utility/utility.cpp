#include "utility.h"
#include <iostream>

namespace utility
{

size_t inputOptionHandler(std::string message, std::vector<std::string> const &options)
{
    std::vector<std::string> valids;
    std::string val;
    message += ':';

    // Loop through the options list and create string for display.
    for (size_t num = 0; num != options.size(); ++num)
    {
        message += '\n' + std::to_string(num) + ". " + options[num];
        valids.push_back(std::to_string(num));
    }

    while (true)
    {
        std::cout << message << "\nType a number:\n";
        std::cin >> val;

        if (std::find(valids.begin(), valids.end(), val) != valids.end())
        {
            std::cout << '\n';
            return std::stoul(val);
        }

        std::cout << val << " is not a valid option, please try again:\n";
    }
}

} // namespace utility
