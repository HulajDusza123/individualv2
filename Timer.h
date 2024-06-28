//
// Created by mrzar on 28.06.2024.
//

#ifndef INDIVIDUALV2_TIMER_H
#define INDIVIDUALV2_TIMER_H


#include <chrono>
class Timer
{
private:
    std::chrono::high_resolution_clock::time_point m_startTime;
    std::chrono::high_resolution_clock::time_point m_endTime;
    std::chrono::microseconds m_duration;
public:

    void Start() { m_startTime = std::chrono::high_resolution_clock::now(); }
    void Stop() { m_endTime = std::chrono::high_resolution_clock::now();
        m_duration = std::chrono::duration_cast<std::chrono::microseconds>(m_endTime - m_startTime	 );
    }
    std::chrono::microseconds GetTime() { return m_duration; }
};


#endif //INDIVIDUALV2_TIMER_H
