#pragma once

#include <iostream>
#include <ctime>
#include <chrono>
#include <string>

#include <iomanip>
#include <sstream>


class Stopwatch {
    using TimePoint = std::chrono::time_point<std::chrono::system_clock>;
    using Duration = std::chrono::duration<double>;

    const std::string _format;
    std::string _value;
    bool _isActive;
    TimePoint _start;


public:
    Stopwatch():
        _format("%H:%M:%S"),
        _value("00:00:00"),
        _isActive(false),
        _start()
    {}
    
    std::string value() {
        if (_isActive) {
            TimePoint now = std::chrono::system_clock::now();     
            return setValue(now);
        }
        return _value;
    }

    TimePoint start() {
        _start = std::chrono::system_clock::now();     
        _isActive = true;
        return _start;
    }
    
    TimePoint stop() {
        TimePoint end = std::chrono::system_clock::now();     
        _isActive = false;
        _value = setValue(end);
        return end;
    }


private:
    std::string setValue(const TimePoint& now) {
        using system_clock = std::chrono::system_clock;
        
        std::time_t startTime = system_clock::to_time_t(_start);
        std::time_t nowTime = system_clock::to_time_t(now - std::chrono::hours(1));
        std::time_t differenceTime = nowTime - startTime;
        std::tm resultTimeStruct = *std::localtime(&differenceTime);

        std::ostringstream output;
        output << std::put_time(&resultTimeStruct, _format.c_str());
        _value = output.str();
        return _value; 
    }
};


