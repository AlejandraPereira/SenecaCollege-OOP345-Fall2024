/*Full Name  : Alejandra Vanessa Pereira Leon
Student ID#: 139273221
Email      : avpleon@myseneca.ca
Section    : NFF
*/
#ifndef SENECA_LOGGER_H
#define SENECA_LOGGER_H
#include "event.h"

namespace seneca{

    struct Logger{
    private:
        Event * events;
        size_t numEvents; // Current number of events stored
        size_t capacity;
        void resize();  // Function to resize the array dynamically
    public:
        Logger();
        ~Logger();

        Logger(const Logger&) = delete;
        Logger& operator=(const Logger&) = delete;

        // Move operations (if needed)
        Logger(Logger&& other) noexcept;
        Logger& operator=(Logger&& other) noexcept;
        
        void addEvent(const Event& event);
        friend std::ostream& operator<<(std::ostream& os, const Logger& logger);
    };
}

#endif // LOGGER_H