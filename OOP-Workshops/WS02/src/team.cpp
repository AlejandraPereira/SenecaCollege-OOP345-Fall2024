/* Full Name  : Alejandra Vanessa Pereira Leon
Student ID#: 139273221
Email      : avpleon@myseneca.ca
Section    : NFF
*/

#include <iostream>
#include <iomanip>
#include "team.h"

using namespace std;

namespace seneca {

    // Constructor with name
    Team::Team(const char* name) 
        : m_teamName(name), m_members(nullptr), m_numMembers(0), m_capacity(2) // Initialize capacity to 2
    {
        m_members = new Character*[m_capacity]; // Allocate memory for members
    }

    // Copy constructor
    Team::Team(const Team& other) 
        : m_teamName(other.m_teamName), m_members(nullptr), m_numMembers(0), m_capacity(other.m_capacity)
    {
        m_members = new Character*[m_capacity]; // Allocate memory
        *this = other; // Use the assignment operator
    }

    // Move constructor
    Team::Team(Team&& other) noexcept 
        : m_teamName(std::move(other.m_teamName)), m_members(other.m_members),
          m_numMembers(other.m_numMembers), m_capacity(other.m_capacity) 
    {
        // Reset the moved object's members
        other.m_members = nullptr;
        other.m_numMembers = 0;
        other.m_capacity = 0;
    }

    // Destructor
    Team::~Team() 
    {
        clear(); // Clear allocated memory
    }

    // Copy assignment operator
    Team& Team::operator=(const Team& other) 
    {
        if (this != &other) 
        {
            clear(); // Clear existing members
            m_teamName = other.m_teamName;
            m_numMembers = other.m_numMembers;
            m_capacity = other.m_capacity;

            // Allocate new memory for m_members
            m_members = new Character*[m_capacity];
            for (size_t i = 0; i < m_numMembers; ++i) 
            {
                m_members[i] = other.m_members[i]->clone(); // Clone each member
            }
        }
        return *this; // Return current object
    }

    // Move assignment operator
    Team& Team::operator=(Team&& other) noexcept 
    {
        if (this != &other) 
        {
            clear(); // Clear existing members
            m_teamName = std::move(other.m_teamName);
            m_members = other.m_members;
            m_numMembers = other.m_numMembers;
            m_capacity = other.m_capacity;

            // Reset the moved object's members
            other.m_members = nullptr;
            other.m_numMembers = 0;
            other.m_capacity = 0;
        }
        return *this; // Return current object
    }

    // Function to clear allocated memory
    void Team::clear() 
    {
        for (size_t i = 0; i < m_numMembers; ++i) 
        {
            delete m_members[i]; // Delete each member
        }
        delete[] m_members; // Delete the array
        m_members = nullptr; // Ensure m_members is null
        m_numMembers = 0; // Reset number of members
        m_capacity = 0; // Reset capacity
    }

    // Function to resize the array
    void Team::resize(size_t newCapacity) 
    {
        Character** newMembers = new Character*[newCapacity]; // Allocate new array
        for (size_t i = 0; i < m_numMembers; ++i) 
        {
            newMembers[i] = m_members[i]; // Copy existing members
        }
        delete[] m_members; // Free old array
        m_members = newMembers; // Update to new array
        m_capacity = newCapacity; // Update capacity
    }

    // Find a member by name
    int Team::findMember(const std::string& name) const 
    {
        for (size_t i = 0; i < m_numMembers; ++i) 
        {
            if (m_members[i]->getName() == name) 
            {
                return static_cast<int>(i); // Member found
            }
        }
        return -1; // Not found
    }

    // Add a character to the team if not already present
    void Team::addMember(const Character* c) 
    {
        if (findMember(c->getName()) != -1) 
        {
            return; // Member already exists
        }

        // Resize if necessary
        if (m_numMembers >= m_capacity) 
        {
            resize(m_capacity * 2); // Double the capacity
        }

        m_members[m_numMembers++] = c->clone(); // Clone and add member
    }

    // Remove a character from the team by name
    void Team::removeMember(const std::string& name) 
    {
        int index = findMember(name);
        if (index != -1) 
        {
            delete m_members[index]; // Delete the character
            for (size_t i = index; i < m_numMembers - 1; ++i) 
            {
                m_members[i] = m_members[i + 1]; // Shift members left
            }
            --m_numMembers; // Decrease member count
        }
    }

    // Returns the character at the specified index or nullptr if out of bounds
    Character* Team::operator[](size_t index) const 
    {
        return (index < m_numMembers) ? m_members[index] : nullptr; // Return member or nullptr
    }

    // Print team members
    void Team::showMembers() const 
    {
        if (m_numMembers == 0) 
        {
            std::cout << "No team." << std::endl; // No members to display
        } 
        else 
        {
            std::cout << "[Team] " << m_teamName << std::endl;
            for (size_t i = 0; i < m_numMembers; ++i) 
            {
                std::cout << "    " << (i + 1) << ": " << *m_members[i] << std::endl; // Print each member
            }
        }
    }
}
