#include "pythonlike/pythonlike.h"
#include <cassert>
#include <string>
#include <vector>

using namespace pythonlike;

int main()
{
    // TEST TEMPLATES IN PYTHONLIKE.H
    std::vector<int> const empty;
    std::vector<int> vec = {1, 3, 5, 2, 4};
    std::vector<int> vecs = {1, 2, 3, 4, 5};
    std::vector<int> vecr = {5, 4, 3, 2, 1};

    assert(sum(empty) == 0);
    assert(max(empty) == 0);
    assert(min(empty) == 0);
    assert(sum(vec) == 15);
    assert(max(vec) == 5);
    assert(min(vec) == 1);
    assert(sorted(vec) == vecs);
    isorted(vec);
    assert(vec == vecs);
    assert(reverse(vecs) == vecr);
    ireverse(vecs);
    assert(vecs == vecr);
    assert(round(3.14159, 3) == 3.142);

    // TEST TEMPLATES IN SLICE.H
    std::vector<int> nums1;
    for (auto num = 0; num != 101; ++num)
        nums1.push_back(num);

    std::vector<int> nums2;
    for (auto num : range(101))
        nums2.push_back(num);

    std::vector<int> nums3;
    for (auto num : view(nums1, 10, 20))
        nums3.push_back(num);

    assert(nums1 == nums2);
    assert(nums3 == slice(nums1, 10, 20));

    // TEST FUNCTIONS IN PRINT.H

    // tests for print() to be implemented.

    assert(fs("hello {}", "abc") == "hello abc");
    assert(fs("hello", "abc") == "hello");               // forgot to add {}.
    assert(fs("hello {} {}", "abc") == "hello abc {}");  // too many {}.
    assert(fs("hello {}") == "hello {}");                // forgot to add arguments.
    assert(fs("hello {}", "abc", "def") == "hello abc"); // too many arguments.
}
