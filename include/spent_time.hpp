#pragma once

#include <chrono>

class SpentTime {
    public:
        SpentTime();
        unsigned long getDuration(bool reset = true);
        void reset(void);
    private:
        std::chrono::high_resolution_clock::time_point _startTime;
};
