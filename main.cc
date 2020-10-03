#include "euler/euler.h"
#include "easy/easy.h"
#include "stopwatch/stopwatch.h"
#include <iostream>

euler::Primetools p;

int main()
{
    easy::print(p.factorPrime(168));
    easy::print(p.factorPrimeSingle(168));
    easy::print(p.factorAll(168));
    
    std::cout << p.divisorSum(168) << '\n';
    std::cout << p.divisorSumProper(168) << '\n';

    std::cout << p.totient(100) << '\n';
}
