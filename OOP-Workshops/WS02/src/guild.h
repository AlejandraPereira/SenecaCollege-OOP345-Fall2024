/*  
    Full Name  : Alejandra Vanessa Pereira Leon 
    Student ID#: 139273221
    Email      : avpleon@myseneca.ca
    Section    : NFF
*/

#ifndef SENECA_GUILD_H
#define SENECA_GUILD_H

#include "character.h"
#include <iostream>
#include <string>

namespace seneca {

    class Guild {
        Character** m_members; // Pointer to an array of Character pointers
        std::string m_name;   // Name of the guild
        int m_extraHP;        // Extra health points for guild members
        int m_count;          // Current number of members
        int m_capacity;       // Current capacity of the member array

    public:
        Guild(); // Default constructor
        Guild(const char* name); // Constructor that initializes the guild with a name

        // Rule of 5
        Guild(const Guild& g); // Copy constructor
        Guild(Guild&& g) noexcept; // Move constructor
        ~Guild(); // Destructor

        Guild& operator=(const Guild& g); // Copy assignment operator
        Guild& operator=(Guild&& g) noexcept; // Move assignment operator

        void addMember(Character* c); // Add member to guild
        void removeMember(const std::string& c); // Remove member by name
        Character* operator[](size_t other) const; 
        void showMembers() const; // Display all guild members
    };

}

#endif // SENECA_GUILD_H
