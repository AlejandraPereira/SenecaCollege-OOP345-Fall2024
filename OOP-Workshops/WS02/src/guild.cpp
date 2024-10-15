/* Full Name  : Alejandra Vanessa Pereira Leon
   Student ID#: 139273221
   Email      : avpleon@myseneca.ca
   Section    : NFF
*/
#include <iostream>
#include "guild.h"
using namespace std;

namespace seneca {
    // Default constructor
    Guild::Guild() 
        : m_members(nullptr), m_name(""), m_extraHP(300), m_count(0), m_capacity(0) {
    }

    // Constructor that initializes the guild with a name
    Guild::Guild(const char* name) 
        : m_members(nullptr), m_name(name), m_extraHP(300), m_count(0), m_capacity(0) {
    }

    // Copy constructor
    Guild::Guild(const Guild& g) 
        : m_name(g.m_name), m_extraHP(g.m_extraHP), m_count(g.m_count), m_capacity(g.m_capacity) {
        m_members = new Character*[m_capacity];
        for (int i = 0; i < m_count; i++) {
            m_members[i] = g.m_members[i]; 
        }
    }

    // Move constructor
    Guild::Guild(Guild&& g) noexcept 
        : m_members(g.m_members), m_name(std::move(g.m_name)), m_extraHP(g.m_extraHP), m_count(g.m_count), m_capacity(g.m_capacity) {
        
        g.m_members = nullptr; 
        g.m_count = 0;        
        g.m_capacity = 0;
    }

    // Destructor
    Guild::~Guild() {
        delete[] m_members; 
    }

    // Copy assignment operator
    Guild& Guild::operator=(const Guild& g) {
        if (this != &g) {
           
            delete[] m_members; 
            m_members = new Character*[g.m_capacity]; // Allocate new memory
            m_count = g.m_count;
            m_capacity = g.m_capacity;
            m_name = g.m_name;
            m_extraHP = g.m_extraHP;

            for (int i = 0; i < m_count; i++) {
                m_members[i] = g.m_members[i]; 
            }
        }
        return *this;
    }

    // Move assignment operator
    Guild& Guild::operator=(Guild&& g) noexcept {
        if (this != &g) {
            // Clean up existing memory
            delete[] m_members;

            m_members = g.m_members; 
            m_name = std::move(g.m_name);
            m_extraHP = g.m_extraHP;
            m_count = g.m_count;
            m_capacity = g.m_capacity;

            // Reset the moved-from object
            g.m_members = nullptr;
            g.m_count = 0;
            g.m_capacity = 0;
        }
        return *this;
    }

    void Guild::addMember(Character* c) {
        // Check for duplicates
        bool flag = false;

        for (int i = 0; i < m_count; i++) {
            if(m_members[i]->getName() == c->getName()) {
            flag = true; // Duplicate found
            break;
            }
        }

        if (!flag) {
            // Resize if necessary
            if (m_count == m_capacity) {
                m_capacity = (m_capacity == 0) ? 2 : m_capacity * 2; // Double capacity if full
                Character** temp = new Character*[m_capacity];

                for (int i = 0; i < m_count; i++) {
                    temp[i] = m_members[i];
                }
                delete[] m_members; // Delete old member array
                m_members = temp; // Point to new array
            }

            // Add new member
            m_members[m_count++] = c; // Add character and increment count

            // Increase new member's maximum health by 300 points
            c->setHealthMax(c->getHealthMax() + m_extraHP);
            c->setHealth(c->getHealthMax()); // Set health to max
        }
    }

    void Guild::removeMember(const std::string& c) {
        int index = -1;

        for (int i = 0; i < m_count; i++) {
            if (m_members[i]->getName() == c) {
                index = i; // Found the character
                break; 
            }
        }

        if (index != -1) {
            
            // Calculate new max health
            int newMaxHealth = m_members[index]->getHealthMax() - m_extraHP;
            if (newMaxHealth < 0) newMaxHealth = 0; 
            m_members[index]->setHealthMax(newMaxHealth);

            // Adjust health if necessary
            if (m_members[index]->getHealth() > newMaxHealth) {
                m_members[index]->setHealth(newMaxHealth);
            }

            // Shift remaining members
            for (int i = index; i < m_count - 1; i++) {
                m_members[i] = m_members[i + 1];
            }

            m_count--; 
        }
    }

    Character* Guild::operator[](size_t other) const {
     return (other < static_cast<size_t>(m_count)) ? m_members[other] : nullptr; // Return member or nullptr 
    }

    // Display all guild members
    void Guild::showMembers() const {
        if (m_members == nullptr) {
            cout << "No guild." << endl;
        } else {
            cout << "[Guild] " << m_name << endl;
            for (int i = 0; i < m_count; i++) {
                cout << setw(4) << "" << i + 1 << ": " << *m_members[i] << endl; 
            }
        }
    }
}
