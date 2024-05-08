#include "math/math.h"
#include "euler/euler.h"
#include "fractions/fractions.h"
#include "stopwatch/stopwatch.h"
#include "pythonlike/pythonlike.h"

#include <vector>
#include <deque>
#include <string>
#include <array>
#include <list>
#include <forward_list>

using namespace std;
using namespace pythonlike;

int main()
{
    vector<int> x = {1, 4, 9, 16, 25};
    vector<int> y = {0, 6, 1, 7, 5, 0, 9, 3, 4, 9};
    vector<string> z = {"anton", "arend", "alwin"};

    print("hello", 1.25, true, z, z);
    print(min(x), max(x), sum(x));
    print(min(y), max(y), ctos(y));
    print(sorted(y));

    string const a = "Lorem ipsum dolor sit amet, consectetur adipiscing elit.";
    char const *b = "Lorem ipsum dolor sit amet, consectetur adipiscing elit.";

    print(slice(b, 0, 5));

    for (auto name : view(z, 1, 3))
        print(name);

    for (auto num : range(1, 11))
        print(num, num * num);

    print(reverse(z));
    ireverse(z);
    print(reverse(string("hello")));
    print(z);
    print(round(3.141515125124, 1));

    Stopwatch timer("hello");
    timer.start();
    cout << "hello world\n";
    timer.time();
    cout << math::binomCoeff(5, 3) << '\n';
    cout << "hello, world" << '\n';
    print(1, 1.25, "hello");
    cout << euler::numDigits(123456789) << '\n';
    auto pp = euler::Primetools{1000};
    print(pp.sieve(100));

    // FRACTIONS
    auto frac1 = Fraction(1, 1);
    auto frac2 = Fraction(-2, 4);
    print("\n\n");

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

    cout <<  4 + frac2 << endl;
    cout << -4 + frac2 << endl;
    cout <<  4 - frac2 << endl;
    cout << -4 - frac2 << endl;
    cout <<  4 * frac2 << endl;
    cout << -4 * frac2 << endl;
    // Division is still not working properly.

    cout << boolalpha << (frac1 < frac2) << endl;    
    cout << boolalpha << (frac1 > frac2) << endl;
    cout << boolalpha << (frac1 == frac2) << endl;
    cout << boolalpha << (frac1 != frac2) << endl;
    cout << boolalpha << (frac1 >= frac2) << endl;
    cout << boolalpha << (frac1 <= frac2) << endl;
}
