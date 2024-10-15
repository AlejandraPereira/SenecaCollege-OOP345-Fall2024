/* Full Name  : Alejandra Vanessa Pereira Leon
   Student ID#: 139273221
   Email      : avpleon@myseneca.ca
   Section    : NFF
*/

#ifndef SENECA_ROGUE_H
#define SENECA_ROGUE_H

#include "characterTpl.h"
#include "weapons.h"
#include "abilities.h"

using namespace std;

namespace seneca {

    template <typename T, typename FirstAbility_t, typename SecondAbility_t>
    class Rogue : public CharacterTpl<T> {
    private:
        int m_baseDefense;        
        int m_baseAttack;         
        FirstAbility_t m_firstAbility;  // First special ability
        SecondAbility_t m_secondAbility; // Second special ability
        Dagger m_weapon;      // Damage from the weapon

    public:
        Rogue(const char* name, int healthMax, int baseAttack, int baseDefense);

        int getAttackAmnt() const;
        int getDefenseAmnt() const;
        Character* clone() const;
        void attack(Character* enemy);
        void takeDamage(int dmg);
    };

    // Constructor
    template <typename T, typename FirstAbility_t, typename SecondAbility_t>
    Rogue<T, FirstAbility_t, SecondAbility_t>::Rogue(const char* name, int healthMax, int baseAttack, int baseDefense)
        : CharacterTpl<T>(name, healthMax), m_baseDefense(baseDefense),m_baseAttack(baseAttack), m_weapon() {
    }

    // Get attack amount
    template<typename T, typename FirstAbility_t, typename SecondAbility_t>
	int Rogue<T, FirstAbility_t, SecondAbility_t>::getAttackAmnt() const
	{
		int damage = m_baseAttack + 2 * static_cast<double>(m_weapon);
		return static_cast<int>(damage);
	}

    // Get defense amount
    template <typename T, typename FirstAbility_t, typename SecondAbility_t>
    int Rogue<T, FirstAbility_t, SecondAbility_t>::getDefenseAmnt() const {
        return m_baseDefense; 
    }

    // Clone function
    template <typename T, typename FirstAbility_t, typename SecondAbility_t>
    Character* Rogue<T, FirstAbility_t, SecondAbility_t>::clone() const {
        return new Rogue(*this); // Clone using the copy constructor
    }

    // Attack function
    template <typename T, typename FirstAbility_t, typename SecondAbility_t>
    void Rogue<T, FirstAbility_t, SecondAbility_t>::attack(Character* enemy) {
        if (enemy) {
            int damage = getAttackAmnt();
            enemy->takeDamage(damage);
            std::cout << "Rogue attacks for " << damage << " damage!" << std::endl;
        }
    }

    // Take damage function
    template <typename T, typename FirstAbility_t, typename SecondAbility_t>
    void Rogue<T, FirstAbility_t, SecondAbility_t>::takeDamage(int dmg) {
       
        CharacterTpl<T>::takeDamage(dmg - m_baseDefense); // Apply defense
        std::cout << "Rogue takes " << dmg << " damage!" << std::endl;
    }

}

#endif // SENECA_ROGUE_H
