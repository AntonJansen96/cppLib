#include "euler/euler.h"
#include "fileio/fileio.h"
#include "fractions/fractions.h"
#include "math/math.h"
#include "pythonlike/pythonlike.h"
#include "stopwatch/stopwatch.h"
#include "utility/utility.h"

#include <array>
#include <cmath>
#include <deque>
#include <forward_list>
#include <list>
#include <string>
#include <vector>

using namespace std;
using namespace pythonlike;

void func()
{
    auto p = euler::Primetools(1000);
    p.sieve(1000);
}

int main()
{
    Stopwatch clock;
    clock.start();

    // EULER

    // UTILITY
    print(utility::num2vec(12345));
    print(utility::vec2num(std::vector<int>{1, 2, 3, 4, 5}));

    // STOPWATCH
    profile(1000, func);

    // PYTHONLIKE
    using grid = std::vector<std::vector<int>>;
    grid g = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    print(g);
    string const xx = "hello world";
    string yy = "hello";
    vector<string> zz = {"hello", "world", "anton"};
    vector<string> const aa = {"hello", "world", "anton"};
    print(xx);
    print(yy);
    print(zz);
    print(aa);
    print(min(std::vector<size_t>{}));
    print(reverse(std::vector<size_t>{}));
    print(slice("hello", 1, 3));  // slice char*
    print(slice("hello"s, 1, 3)); // slice std::string

    // FRACTIONS
    auto frac1 = Fraction(1, 1);
    auto frac2 = Fraction(-2, 4);
    cout << Fraction(1, 3) << endl;
    cout << Fraction(1, 3).approx() << endl;
    cout << Fraction(2, 4) << endl;
    cout << Fraction(-1, 3) << endl;
    cout << Fraction(1, -3) << endl;
    cout << Fraction(-1, -3) << endl;
    cout << Fraction(-1, 0) << endl;

    cout << frac1 + frac2 << endl;
    cout << frac1 - frac2 << endl;
    cout << frac1 * frac2 << endl;
    cout << frac1 / frac2 << endl;

    cout << 4 + frac2 << endl;
    cout << -4 + frac2 << endl;
    cout << 4 - frac2 << endl;
    cout << -4 - frac2 << endl;
    cout << 4 * frac2 << endl;
    cout << -4 * frac2 << endl;

    cout << 4 / frac2 << endl;     // should return -8
    cout << -4 / frac2 << endl;    // should return 8
    cout << frac2 / 4 << endl;     // should return -1/8
    cout << frac2 / -4 << endl;    // should return 1/8
    cout << (frac2 /= -4) << endl; // should return 1/8

    cout << boolalpha << (frac1 < frac2) << endl;
    cout << boolalpha << (frac1 > frac2) << endl;
    cout << boolalpha << (frac1 == frac2) << endl;
    cout << boolalpha << (frac1 != frac2) << endl;
    cout << boolalpha << (frac1 >= frac2) << endl;
    cout << boolalpha << (frac1 <= frac2) << endl;

    // MATH
    cout << math::mulmod(130, 15, 2) << endl;
    cout << math::mulmod(130, 15, 0) << endl;
    cout << math::powmod(15, 6, 6) << endl;
    cout << math::powmod(15, 6, 0) << endl;
    cout << math::modinverse(13, 2) << endl;
    cout << math::modinverse(13, 0) << endl;
    cout << math::fastpow(7, 5) << endl;
    cout << math::fastpow(13, 5) << endl;
    cout << math::intlog10(1412411) << endl;
    cout << math::factorial(5) << endl;
    cout << math::factorial(0) << endl;
    cout << math::factorial(-2) << endl;
    cout << math::binom(18, 7) << endl; // should be 31824
    cout << math::gcd(23142, 155) << endl;

    print(fs("Executing tests took {}.", clock));
}
