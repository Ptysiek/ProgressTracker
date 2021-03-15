
#include "Stopwatch.h"

#include <array>
#include <curses.h>
#include <string>
#include <vector>

#include <iostream>
#include <sstream>
#include <string>


int main() {

    Stopwatch stopwatch;
    std::cout << stopwatch.value();
    stopwatch.start();
    std::cout << stopwatch.value();

    for (int i = 0; i < 1000; ++i) 
    for (int i = 0; i < 1000000; ++i) { std::cout << ""; }
    
    
    std::cout << stopwatch.value();

    for (int i = 0; i < 1000; ++i) 
    for (int i = 0; i < 1000000; ++i) { std::cout << ""; }
    stopwatch.stop();
    std::cout << stopwatch.value();

    /*
    //using Time_t

    TimePoint test;
    std::time_t t_c = std::chrono::system_clock::to_time_t(test);
    std::cout << t_c << "\n";

    test = std::chrono::system_clock::now();
    t_c = std::chrono::system_clock::to_time_t(test);
    std::cout << t_c << "\n";

    const std::string format = "%d.%m.%Y %H:%M:%S";
    
    //std::cout << std::put_time(&t_c, format.c_str()); // << "\n";
*/
/*
        std::time_t t;
        //t = std::time(nullptr);
         
        std::tm tm; 
        tm = *std::localtime(&t);
        std::tm tm_c = *std::localtime(&t_c);
        
        std::ostringstream oss;
        oss << std::put_time(&tm, format.c_str()) << "\n";
        //oss << std::put_time(std::localtime(&t_c), format.c_str()) << "\n";
        oss << std::put_time(&tm_c, format.c_str());
        
        std::cout << oss.str() << "\n";
//*/

    std::cout << "\n\n";
    return 0;
}
                                                          
