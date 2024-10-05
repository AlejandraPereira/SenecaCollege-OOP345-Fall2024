/*Full Name  : Alejandra Vanessa Pereira Leon
Student ID#: 139273221
Email      : avpleon@myseneca.ca
Section    : NFF
*/
#ifndef SENECA_TIMEMONITOR_H
#define SENECA_TIMEMONITOR_H

#include <chrono>
#include <string>
#include "event.h"

namespace seneca {
    
    class TimeMonitor {
    private:
        std::chrono::high_resolution_clock::time_point start_time;
        std::string event_name;

    public:
        void startEvent(const char* name); // Start a new event
        Event stopEvent(); // Stop the current event and return an Event object
    };
}

#endif // SENECA_TIMEMONITOR_H
