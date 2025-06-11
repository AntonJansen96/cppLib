#include "stopwatch/stopwatch.h"
#include <cstdlib>

int main()
{
    stopwatch::Stopwatch clock, clock1, clock2, clock3, clock4, clock5, clock6, clock7,
        clock8;

    clock.start();

    // euler
    clock1.start();
    system("build/test_euler");
    system("build/test_primetools");
    clock1.stop();

    // fileio
    clock2.start();
    system("build/test_fileio");
    clock2.stop();

    // fractions
    clock3.start();
    system("build/test_fractions");
    clock3.stop();

    // math
    clock4.start();
    system("build/test_math");
    clock4.stop();

    // pythonlike
    clock5.start();
    system("build/test_pythonlike");
    clock5.stop();

    // probability
    clock6.start();
    system("build/test_probability");
    clock6.stop();

    // stopwatch
    clock7.start();
    system("build/test_stopwatch");
    clock7.stop();

    // utility
    clock8.start();
    system("build/test_utility");
    clock8.stop();

    std::cout << "\nTest performance summary:\n";
    std::cout << "Executing euler tests took " << clock1 << ".\n";
    std::cout << "Executing fileio tests took " << clock2 << ".\n";
    std::cout << "Executing fractions tests took " << clock3 << ".\n";
    std::cout << "Executing math tests took " << clock4 << ".\n";
    std::cout << "Executing pythonlike tests took " << clock5 << ".\n";
    std::cout << "Executing probability tests took " << clock6 << ".\n";
    std::cout << "Executing stopwatch tests took " << clock7 << ".\n";
    std::cout << "Executing utility tests took " << clock8 << ".\n";
    std::cout << "Total time is " << clock << ".\n";
}
