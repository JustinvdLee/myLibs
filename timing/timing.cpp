#include "timing.h"

double Timing::stop() {
    double t = duration<double>(system_clock::now()-start).count();
    restart();
    return t; 
}
