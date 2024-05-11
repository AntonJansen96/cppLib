#include "utility/utility.h"
#include <cassert>

int main()
{
    std::vector<int> const vec = {1, 2, 3, 4, 5};
    assert(utility::num2vec(12345) == vec);
    assert(utility::vec2num(vec) == 12345);
}
