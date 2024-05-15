#include "fileio/fileio.h"
#include <cassert>

int main()
{
    auto const x = fileio::file2vector("data/text.txt", ' ');
    assert(x[0] == "total");
    assert(x[1] == "104");
    assert(x.back() == "text.txt");

    std::vector<int64_t> const y = {1965, 416,  548,  126,  182,  41,  43,
                                    1558, 1378, 1823, 4855, 1572, 202, 0};
    assert(fileio::loadCol_i("data/text.txt", 4, 1) == y);
    assert(fileio::loadVal("data/text.txt", 3, 3) == "staff");

    std::vector<std::vector<double>> const z = {
        {0.0, 1.0, 2.0, 3.0, 4.0, 5.0, 6.0, 7.0, 8.0, 9.0, 10.0},
        {0.9997, 0.036, 0.0353, 0.0413, -0.0015, -0.0445, -0.0238, -0.0072, 0.012,
         0.0167, -0.0041}};
    assert(fileio::loadxvg("data/cphmd-coord-1.xvg") == z);
}
