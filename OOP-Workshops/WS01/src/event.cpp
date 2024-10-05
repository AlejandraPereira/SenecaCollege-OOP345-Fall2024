/*Full Name  : Alejandra Vanessa Pereira Leon
Student ID#: 139273221
Email      : avpleon@myseneca.ca
Section    : NFF
*/
#include "event.h"
#include "settings.h"
#include <iostream>
#include <iomanip>

namespace seneca {

    Event::Event()
        : event_name(""), event_duration(0) {}

    Event::Event(const char* name, const std::chrono::nanoseconds& duration)
        : event_name(name), event_duration(duration) {}

    std::string Event::getName() const {
        return event_name;
    }

    std::chrono::nanoseconds Event::getDuration() const {
        return event_duration;
    }

    std::ostream& operator<<(std::ostream& os, const Event& event) {
        static int count = 1;

        os << std::setw(2) << count++ << ": ";

        os.fill(' ');
        os.width(40);
        os << event.event_name;

        os << " -> ";

        // Determinate the timeUnit and show the value 
        if (g_settings.m_time_units == "microseconds") {
            os << std::setw(TimeUnits::Microseconds) << std::chrono::duration_cast<std::chrono::microseconds>(event.event_duration).count();
        }
        else if (g_settings.m_time_units == "milliseconds") {
            os << std::setw(TimeUnits::Milliseconds) << std::chrono::duration_cast<std::chrono::milliseconds>(event.event_duration).count();
        }
        else if (g_settings.m_time_units == "seconds") {
            os << std::setw(TimeUnits::Seconds) << std::chrono::duration_cast<std::chrono::seconds>(event.event_duration).count();
        }
        else {
            os << std::setw(TimeUnits::Nanoseconds) << event.event_duration.count();
        }

        os << ' ' << g_settings.m_time_units;

        return os;
    }
}
