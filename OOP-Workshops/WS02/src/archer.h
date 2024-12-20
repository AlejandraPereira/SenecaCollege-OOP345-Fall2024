/* Full Name  : Alejandra Vanessa Pereira Leon
   Student ID#: 139273221
   Email      : avpleon@myseneca.ca
   Section    : NFF
*/

#ifndef SENECA_ARCHER_H
#define SENECA_ARCHER_H

#include "characterTpl.h"
#include "weapons.h"
#include "health.h"
#include <iostream> 
#include <string>   
#include <algorithm> 

using namespace std;

namespace seneca {
    template<typename Weapon_t>
    class Archer : public CharacterTpl<seneca::SuperHealth> {
    private:
        int m_baseAttack;
        int m_baseDefense;
        Weapon_t m_weapon;

    public:
        // Constructor
        Archer(const char* name, int healthMax, int baseAttack, int baseDefense, Weapon_t weapon);

        // Member functions
        int getAttackAmnt() const;
        int getDefenseAmnt() const;
        Character* clone() const;
        void attack(Character* enemy);
        void takeDamage(int dmg);
    };

    // Constructor
    template<typename Weapon_t>
    Archer<Weapon_t>::Archer(const char* name, int healthMax, int baseAttack, int baseDefense, Weapon_t weapon)
        : CharacterTpl<seneca::SuperHealth>(name, healthMax), m_baseAttack(baseAttack), m_baseDefense(baseDefense), m_weapon(weapon) {
    }

    // Get attack amount
    template<typename Weapon_t>
    int Archer<Weapon_t>::getAttackAmnt() const {
        int damage = static_cast<int>(1.3 * m_baseAttack);
        return damage;
    }

    // Get defense amount
    template<typename Weapon_t>
    int Archer<Weapon_t>::getDefenseAmnt() const {
        int defense = static_cast<double>(1.2 * m_baseDefense);
        return defense;
    }

    // Clone function
    template<typename Weapon_t>
    Character* Archer<Weapon_t>::clone() const {
        return new Archer(*this);
    }

    // Attack function
    template<typename Weapon_t>
    void Archer<Weapon_t>::attack(Character* enemy) {
        std::string name = this->getName();
        std::string enemyName = enemy->getName();

        cout << name << " is attacking " << enemyName << "." << endl;

        int damage = getAttackAmnt();

        cout << "Archer deals " << damage << " ranged damage!" << endl;

        enemy->takeDamage(damage);
    }

    // Take damage function
    template<typename Weapon_t>
    void Archer<Weapon_t>::takeDamage(int dmg) {
        std::string name = this->getName();
        int offense = getAttackAmnt();
        int defense = getDefenseAmnt();

        cout << name << " is attacked for " << offense << " damage." << endl;
        cout << '\t' << "Archer has a defense of " << defense << ". Reducing damage received." << endl;

        dmg -= getDefenseAmnt();
        dmg = std::max(dmg, 0);

        CharacterTpl<seneca::SuperHealth>::takeDamage(dmg);
    }
}

#endif // SENECA_ARCHER_H
