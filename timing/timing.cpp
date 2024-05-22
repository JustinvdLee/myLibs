#include "timing.h"

double Timing::stop() {
    const auto result = untillNow();
    reset();
    return result; 
}

