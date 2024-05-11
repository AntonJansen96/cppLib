#include "pythonlike/pythonlike.h"
#include <string>
#include <vector>

using namespace pythonlike;

int main()
{
    using grid = std::vector<std::vector<int>>;
    grid g = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    print(g);
    std::string const xx = "hello world";
    std::string yy = "hello";
    std::vector<std::string> zz = {"hello", "world", "anton"};
    std::vector<std::string> const aa = {"hello", "world", "anton"};
    print(xx);
    print(yy);
    print(zz);
    print(aa);
    print(min(std::vector<size_t>{}));
    print(reverse(std::vector<size_t>{}));
    print(slice("hello", 1, 3));              // slice char*
    print(slice(std::string("hello"), 1, 3)); // slice std::string
}
