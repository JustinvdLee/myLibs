/*
 *  lib: timing
 *      Class to time code execution
 *      Gets the start time when constructed or when reset is called
 *      Calculates the time when untillNow() or stop() is called
 *
 *  Properties:
 *      Date:   2024-05-22
 *      Status: Must haves completed
 *  
 *  Improvements:
 *      Added ease of use
 *      Functions with other return types (instead of seconds as a double)
 */
#pragma once
#include <chrono>

using namespace std::chrono;

class Timing {
public:

    /*! @brief restart the timer */
    inline void reset() { start = system_clock::now(); }
    
    /*! @brief calculate the time spent untill now
     *  @return the time in seconds since the last reset call */
    inline double untillNow() { return duration<double>(system_clock::now()-start).count(); }

    /*! @brief calculate the time spent and reset the clock
     *  @return the time in seconds since the last reset call */
    double stop();

private:
    time_point<system_clock> start = system_clock::now();    
};

