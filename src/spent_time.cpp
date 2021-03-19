#include "spent_time.hpp"

SpentTime::SpentTime() {
    this->reset();
}

void SpentTime::reset(void) {
    this->_startTime = std::chrono::high_resolution_clock::now();
}

unsigned long SpentTime::getDuration(bool reset) {
    unsigned long d = std::chrono::duration_cast<std::chrono::microseconds>(
        std::chrono::high_resolution_clock::now() - this->_startTime
    ).count();

    if (reset) {
        this->reset();
    }

    return d;
}