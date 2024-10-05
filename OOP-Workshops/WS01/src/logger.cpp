/*Full Name  : Alejandra Vanessa Pereira Leon
Student ID#: 139273221
Email      : avpleon@myseneca.ca
Section    : NFF
*/
#include "logger.h"
#include "event.h"
#include <iostream>

namespace seneca {

    Logger::Logger() : events(nullptr), numEvents(0), capacity(0) {}

    Logger::~Logger() {
        delete[] events;
    }

    Logger::Logger(Logger&& other) noexcept : events(other.events), numEvents(other.numEvents), capacity(other.capacity) {
        other.events = nullptr;
        other.numEvents = 0;
        other.capacity = 0;
    }

    Logger& Logger::operator=(Logger&& other) noexcept {
        if (this != &other) {
            delete[] events;

            events = other.events;
            numEvents = other.numEvents;
            capacity = other.capacity;

            other.events = nullptr;
            other.numEvents = 0;
            other.capacity = 0;
        }
        return *this;
    }

    void Logger::resize() {
        size_t newCapacity = capacity == 0 ? 2 : capacity * 2;
        Event* newEvents = new Event[newCapacity];

        for (size_t i = 0; i < numEvents; ++i) {
            newEvents[i] = events[i]; // Copy existing events to the new array
        }

        delete[] events; // Free the old array
        events = newEvents;
        capacity = newCapacity;
    }

    void Logger::addEvent(const Event& event) {
        if (numEvents == capacity) {
            resize(); // Resize the array if it's full
        }

        events[numEvents++] = event; // Add the new event and increment numEvents
    }

    std::ostream& operator<<(std::ostream& os, const Logger& logger) {
        for (size_t i = 0; i < logger.numEvents; ++i) {
            os << logger.events[i] << std::endl; // Use Event's overloaded operator<<
        }
        return os;
    }

}
