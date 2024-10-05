/*Full Name  : Alejandra Vanessa Pereira Leon
Student ID#: 139273221
Email      : avpleon@myseneca.ca
Section    : NFF
*/
#include "timeMonitor.h"

namespace seneca {

    void TimeMonitor::startEvent(const char* name) {
        event_name = name; // Record the name of the event
        start_time = std::chrono::high_resolution_clock::now(); // Record the start time
    }

    Event TimeMonitor::stopEvent() {
        auto end_time = std::chrono::high_resolution_clock::now(); // Record the end time
        auto duration = std::chrono::duration_cast<std::chrono::nanoseconds>(end_time - start_time); // Calculate the duration

        // Create and return an Event object with the name and duration
        return Event(event_name.c_str(), duration);
    }
}
