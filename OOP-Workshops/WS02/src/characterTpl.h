/* Full Name  : Alejandra Vanessa Pereira Leon
   Student ID#: 139273221
   Email      : avpleon@myseneca.ca
   Section    : NFF
*/
#ifndef SENECA_CHARACTERTPL_H
#define SENECA_CHARACTERTPL_H

#include <iostream>
#include "character.h" 
#include "health.h"
using namespace std;


namespace seneca { 
    template <typename T>
    class CharacterTpl : public Character {
    private: 
        int m_healthMax;  // Max health
        T m_health;       // Current health

    public: 
        CharacterTpl(const char* name, int healthMax) 
            : Character(name), m_healthMax(healthMax) {
            m_health = healthMax; 
        }

        void takeDamage(int dmg) override {
            m_health -= dmg; 
            if (m_health <= 0) {
                m_health = 0;
                std::cout << setw(4) << "" << getName() << " has been defeated!" << std::endl;
            } else {
                std::cout << setw(4) << "" <<getName() << " took " << dmg << " damage, "
                          << m_health << " health remaining." << std::endl;
            }
        }

        int getHealth() const override {
            return static_cast<int>(m_health);
        }

        int getHealthMax() const override {
            return m_healthMax;  
        }

        void setHealth(int health) override {
            m_health = health;
        }

        void setHealthMax(int health) override {
            m_healthMax = health;  
            m_health = health;      
        }
    };
}

#endif // SENECA_CHARACTERTPL_H
