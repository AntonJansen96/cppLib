#include "stopwatch.h"

namespace stopwatch
{

// Start and run the progress counter thread (main code).
void ProgressReport::run()
{
    d_timer.start();
    d_progress_thread = std::thread(
        [&]()
        {
            size_t runtime = 0;
            while (d_progress < d_total)
            {
                progformat(100.0 * d_progress / d_total,
                           runtime * d_update * 1'000'000);
                std::this_thread::sleep_for(std::chrono::milliseconds(d_update));
                ++runtime;
            }

            progformat(100, d_timer.rawtime());
            std::cout << std::endl;
        });
}

// Format user update.
void ProgressReport::progformat(double percent, size_t rawtime) const
{
    std::cout << "\rProgress: " << std::fixed << std::setprecision(2) << std::setw(5)
              << percent << "%, runtime " << Stopwatch::format(rawtime) << "   "
              << std::flush;
}

} // namespace stopwatch
