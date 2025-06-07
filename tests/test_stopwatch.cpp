#include "stopwatch/stopwatch.h"
#include <cassert>

using namespace stopwatch;

void func()
{
    sleep(0.000001);
}

int main()
{
    Stopwatch clock;
    clock.start();

    // Create a Stopwatch object
    Stopwatch sw;

    // Start the Stopwatch
    sw.start();

    // Sleep for a while to let the Stopwatch run
    sleep(0.01);

    // Check if the Stopwatch is running
    assert(sw.isrunning());

    // Get the raw time
    auto raw_time = sw.rawtime();
    assert(raw_time > 0);

    // Stop the Stopwatch
    sw.stop();

    // Check if the Stopwatch is running
    assert(!sw.isrunning());

    // Get the time
    auto time = sw.rawtime();
    assert(time > 0);

    // Reset the Stopwatch
    sw.reset();

    // Get the time
    assert(sw.rawtime() == 0);

    // Test the description
    sw.description() = "Test Stopwatch";
    assert(sw.description() == "Test Stopwatch");

    // Test the copy constructor
    Stopwatch sw2(sw);
    assert(sw2.description() == "Test Stopwatch");

    // Test the move constructor
    Stopwatch sw3(std::move(sw2));
    assert(sw3.description() == "Test Stopwatch");

    // Test the copy assignment operator
    sw2 = sw;
    assert(sw2.description() == "Test Stopwatch");

    // Test the move assignment operator
    sw2 = std::move(sw3);
    assert(sw2.description() == "Test Stopwatch");

    // Test the addition operator
    Stopwatch sw4 = sw + sw2;
    assert(sw4.rawtime() == sw.rawtime() + sw2.rawtime());

    // Test the subtraction operator
    Stopwatch sw5 = sw - sw2;
    assert(sw5.rawtime() == sw.rawtime() - sw2.rawtime());
}
