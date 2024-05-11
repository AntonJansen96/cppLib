#include "stopwatch/stopwatch.h"
#include <iostream>

void func()
{
    sleep(0.000001);
}

int main()
{
    std::cout << "testing profile function.\n";
    std::cout << profile(func, 1000) << '\n';

    Stopwatch clock;
    clock.start();

    // Create a Stopwatch object
    Stopwatch sw;
    std::cout << "Created a Stopwatch object.\n";

    // Start the Stopwatch
    sw.start();
    std::cout << "Started the Stopwatch.\n";

    // Sleep for a while to let the Stopwatch run
    sleep(0.01);
    std::cout << "Slept for 10ms.\n";

    // Check if the Stopwatch is running
    std::cout << "Is the Stopwatch running? " << sw.isrunning() << '\n';

    // Get the raw time
    std::cout << "Raw time: " << sw.rawtime() << '\n';

    // Stop the Stopwatch
    sw.stop();
    std::cout << "Stopped the Stopwatch.\n";

    // Check if the Stopwatch is running
    std::cout << "Is the Stopwatch running? " << sw.isrunning() << '\n';

    // Get the time
    std::cout << "Time: " << sw << '\n';

    // Reset the Stopwatch
    sw.reset();
    std::cout << "Reset the Stopwatch.\n";

    // Get the time
    std::cout << "Time: " << sw << '\n';

    // Test the description
    sw.description() = "Test Stopwatch";
    std::cout << "Description: " << sw.description() << '\n';

    // Test the copy constructor
    Stopwatch sw2(sw);
    std::cout << "Created a copy of the Stopwatch.\n";

    // Test the move constructor
    Stopwatch sw3(std::move(sw2));
    std::cout << "Moved the Stopwatch.\n";

    // Test the copy assignment operator
    sw2 = sw;
    std::cout << "Copied the Stopwatch.\n";

    // Test the move assignment operator
    sw2 = std::move(sw3);
    std::cout << "Moved the Stopwatch.\n";

    // Test the comparison operators
    std::cout << "Are the two Stopwatches equal? " << (sw == sw2) << '\n';
    std::cout << "Are the two Stopwatches not equal? " << (sw != sw2) << '\n';
    std::cout << "Is the first Stopwatch less than the second? " << (sw < sw2) << '\n';
    std::cout << "Is the first Stopwatch greater than the second? " << (sw > sw2)
              << '\n';
    std::cout << "Is the first Stopwatch less than or equal to the second? "
              << (sw <= sw2) << '\n';
    std::cout << "Is the first Stopwatch greater than or equal to the second? "
              << (sw >= sw2) << '\n';

    // Test the addition operator
    Stopwatch sw4 = sw + sw2;
    std::cout << "Added two Stopwatches. Time: " << sw4 << '\n';

    // Test the subtraction operator
    Stopwatch sw5 = sw - sw2;
    std::cout << "Subtracted two Stopwatches. Time: " << sw5 << '\n';
}
