#include "pythonlike/pythonlike.h"
#include <cassert>
#include <sstream>
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

    // TEST TEMPLATES IN PRINT.H

    // Define various non-const primitive types, objects, and containers.
    int t1 = 1;
    float t2 = 3.14;
    bool t3 = true;
    char t4 = 'a';
    const char *t5 = "hello";
    std::string t6 = "world";
    std::vector<int> t7 = {1, 2, 3, 4, 5};
    std::vector<char> t8 = {'a', 'b', 'c', 'd', 'e'};
    std::vector<const char *> t9 = {"hello", "world"};
    std::vector<std::string> t10 = {"some", "string"};
    std::ostringstream t11;
    t11 << "some ostream text";
    std::stringstream t12;
    t12 << "some stringstream text";
    std::vector<std::vector<int>> t13 = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    auto t14 = std::make_pair("hello", 3.14159);
    auto t15 = std::make_tuple(1, 1.15, "hello", std::vector<int>{1, 2, 3});

    // Define various const primitive types, objects, and containers.
    const int t1c = 1;
    const float t2c = 3.14;
    const bool t3c = true;
    const char t4c = 'a';
    const char *t5c = "hello";
    const std::string t6c = "world";
    const std::vector<int> t7c = {1, 2, 3, 4, 5};
    const std::vector<char> t8c = {'a', 'b', 'c', 'd', 'e'};
    const std::vector<const char *> t9c = {"hello", "world"};
    const std::vector<std::string> t10c = {"some", "string"};
    const std::vector<std::vector<int>> t13c = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    const auto t14c = std::make_pair("hello", 3.14159);
    const auto t15c = std::make_tuple(1, 1.15, "hello", std::vector<int>{1, 2, 3});

    std::streambuf *oldCoutStreamBuf = std::cout.rdbuf();
    std::ostringstream strCout;

    std::cout.rdbuf(strCout.rdbuf());
    print();
    std::cout.rdbuf(oldCoutStreamBuf);
    assert(strCout.str() == "\n");
    strCout.str("");

    std::cout.rdbuf(strCout.rdbuf());
    print(t1, t2, t3, t4, t5, t6);
    std::cout.rdbuf(oldCoutStreamBuf);
    assert(strCout.str() == "1 3.14 true a hello world\n");
    strCout.str("");

    std::cout.rdbuf(strCout.rdbuf());
    print(&t11, &t12);
    std::cout.rdbuf(oldCoutStreamBuf);
    assert(strCout.str() == "some ostream text some stringstream text\n");
    strCout.str("");

    std::cout.rdbuf(strCout.rdbuf());
    print(t7, t8);
    std::cout.rdbuf(oldCoutStreamBuf);
    assert(strCout.str() == "[1, 2, 3, 4, 5] ['a', 'b', 'c', 'd', 'e']\n");
    strCout.str("");

    std::cout.rdbuf(strCout.rdbuf());
    print(t9, t10);
    std::cout.rdbuf(oldCoutStreamBuf);
    assert(strCout.str() == "['hello', 'world'] ['some', 'string']\n");
    strCout.str("");

    std::cout.rdbuf(strCout.rdbuf());
    print(t13);
    std::cout.rdbuf(oldCoutStreamBuf);
    assert(strCout.str() == "[[1, 2, 3], [4, 5, 6], [7, 8, 9]]\n");
    strCout.str("");

    std::cout.rdbuf(strCout.rdbuf());
    print(t14);
    std::cout.rdbuf(oldCoutStreamBuf);
    assert(strCout.str() == "('hello', 3.14159)\n");
    strCout.str("");

    std::cout.rdbuf(strCout.rdbuf());
    print(t15);
    std::cout.rdbuf(oldCoutStreamBuf);
    assert(strCout.str() == "(1, 1.15, 'hello', [1, 2, 3])\n");
    strCout.str("");

    std::cout.rdbuf(strCout.rdbuf());
    print();
    std::cout.rdbuf(oldCoutStreamBuf);
    assert(strCout.str() == "\n");
    strCout.str("");

    std::cout.rdbuf(strCout.rdbuf());
    print(t1c, t2c, t3c, t4c, t5c, t6c);
    std::cout.rdbuf(oldCoutStreamBuf);
    assert(strCout.str() == "1 3.14 true a hello world\n");
    strCout.str("");

    std::cout.rdbuf(strCout.rdbuf());
    print(t7c, t8c);
    std::cout.rdbuf(oldCoutStreamBuf);
    assert(strCout.str() == "[1, 2, 3, 4, 5] ['a', 'b', 'c', 'd', 'e']\n");
    strCout.str("");

    std::cout.rdbuf(strCout.rdbuf());
    print(t9c, t10c);
    std::cout.rdbuf(oldCoutStreamBuf);
    assert(strCout.str() == "['hello', 'world'] ['some', 'string']\n");
    strCout.str("");

    std::cout.rdbuf(strCout.rdbuf());
    print(t13c);
    std::cout.rdbuf(oldCoutStreamBuf);
    assert(strCout.str() == "[[1, 2, 3], [4, 5, 6], [7, 8, 9]]\n");
    strCout.str("");

    std::cout.rdbuf(strCout.rdbuf());
    print(t14c);
    std::cout.rdbuf(oldCoutStreamBuf);
    assert(strCout.str() == "('hello', 3.14159)\n");
    strCout.str("");

    std::cout.rdbuf(strCout.rdbuf());
    print(t15c);
    std::cout.rdbuf(oldCoutStreamBuf);
    assert(strCout.str() == "(1, 1.15, 'hello', [1, 2, 3])\n");
    strCout.str("");

    // TEST TEMPLATES IN SLICE.H

    assert(fs("hello {}", "abc") == "hello abc");
    assert(fs("hello", "abc") == "hello");               // forgot to add {}.
    assert(fs("hello {} {}", "abc") == "hello abc {}");  // too many {}.
    assert(fs("hello {}") == "hello {}");                // forgot to add arguments.
    assert(fs("hello {}", "abc", "def") == "hello abc"); // too many arguments.
}
