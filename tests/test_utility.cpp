#include "utility/utility.h"
#include <iostream>

int main()
{
    utility::num2vec(12345);
    std::cout << utility::vec2num(std::vector<int>{1, 2, 3, 4, 5}) << '\n';
}
