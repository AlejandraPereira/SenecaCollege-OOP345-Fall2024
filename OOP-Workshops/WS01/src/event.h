/*Full Name  : Alejandra Vanessa Pereira Leon
Student ID#: 139273221
Email      : avpleon@myseneca.ca
Section    : NFF
*/
#ifndef SENECA_EVENT_H
#define SENECA_EVENT_H

#include <string>
#include <chrono>
#include <iostream>
namespace seneca {

    enum TimeUnits {
		Seconds = 2,
		Milliseconds = 5,
		Microseconds = 8,
		Nanoseconds = 11
	};
    class Event{
    private:

        std::string event_name;
        std::chrono::nanoseconds event_duration;

    public:

        Event();
        Event(const char* name, const std::chrono::nanoseconds& duration);
        std::string getName() const;
        std::chrono::nanoseconds getDuration() const;

        friend std::ostream& operator<<(std::ostream& os, const Event& event);

    };
}

#endif // EVENT_H