/*
 *  lib: pid
 *      Library that acts as a pid controller
 *      With the constructor, you input the PID values
 *      For each step, you input the error as a factor of your set point
 *      It then calculates what your next input should be
 *
 *  Properties:
 *      Date:   2024-05-29
 *      Status: In progress
 *  
 *  Improvements:
 *      Make it work
 *      Implement I and D calculation
 */
#pragma once
#include "ringbuffer.h"

class PID {
public:

    /* @brief PID class
     * @param _setPoint the setPoint of the system
     * @param _Kp the proportional factor 
     * @param _Ki the integrational factor
     * @param _Kd the differential factor */
    PID(const float, const float, const float, const float);

    /* @brief calculate the PID values and add them
     * @param _input the measured input value
     * @return the calculated result */
    float pidCalculation(const float);

    /* getters and setters */

    float getSetPoint() const { return setPoint; }
    void setSetPoint(const float _setPoint) { setPoint = _setPoint; }

    float getKp() const { return Kp; }
    float getKi() const { return Ki; }
    float getKd() const { return Kd; }

    void setKp(const float _Kp) { (_Kp > 0.0) ? Kp = _Kp : Kp = -_Kp; }
    void setKi(const float _Ki) { (_Ki > 0.0) ? Ki = _Ki : Ki = -_Ki; }
    void setKd(const float _Kd) { (_Kd > 0.0) ? Kd = _Kd : Kd = -_Kd; }

private:
    float Kp = 1.0;
    float Ki = 0.0;
    float Kd = 0.0;
    float setPoint = 0.0;

    float pValue() const { return Kp * input.read(); }
    float iValue() const { return 0.0f; }   // for testing
    float dValue() const { return 0.0f; }   // for testing

    RingBuffer<float> input, output;
};

