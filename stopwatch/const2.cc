#include "stopwatch.h"

// Construct Stopwatch object, specify description and start.
Stopwatch::Stopwatch(std::string const &description)
:
    d_start(timeNow),
    d_description(description)
{}
