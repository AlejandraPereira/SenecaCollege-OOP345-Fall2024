/*Full Name  : Alejandra Vanessa Pereira Leon
Student ID#: 139273221
Email      : avpleon@myseneca.ca
Section    : NFF
*/

#ifndef SENECA_TEAM_H
#define SENECA_TEAM_H

#include <string>
#include "character.h"
namespace seneca {
    class Team {
    private:
        std::string m_teamName;
        Character** m_members; // Array of pointers to Character objects
        size_t m_numMembers;   // Number of current members in the team
        size_t m_capacity;     // Capacity of the array (max number of members)


        void clear();   // Function to clear allocated memory
        void resize(size_t newCapacity); // Function to resize the array
        int findMember(const std::string& name) const; // Function to find a character by name

    public:
       
        Team(const char* name = "No team");

        // Rule of 5
        ~Team();
        Team(const Team& other);
        Team(Team&& other) noexcept;
        Team& operator=(const Team& other);
        Team& operator=(Team&& other) noexcept;

        void addMember(const Character* c); // Adds a character to the team if not already present
        void removeMember(const std::string& name); // Removes a character from the team by name
        Character* operator[](size_t other) const; // Returns the character at the specified index or nullptr if out of bounds
        void showMembers() const;   // Prints the team members
    };
}

#endif // SENECA_TEAM_H
