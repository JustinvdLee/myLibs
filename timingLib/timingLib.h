#pragma once

#include <chrono>
using namespace std::chrono;

class Timing {
public:
    void restart() { start = system_clock::now(); }
    double stop();

private:
    time_point<system_clock> start {system_clock::now()};    
};

