#include "pid.h"

PID::PID(const float _setPoint, const float _Kp, const float _Ki, const float _Kd) : 
    setPoint(_setPoint),
    input (RingBuffer<float>(6)),
    output(RingBuffer<float>(2))
{
    setKp(_Kp);
    setKi(_Ki);
    setKd(_Kd);
}

float PID::pidCalculation(const float _input)
{
    input.write(_input);
    return (pValue() + iValue() + dValue());
}


