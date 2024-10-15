/* Full Name  : Alejandra Vanessa Pereira Leon
   Student ID#: 139273221
   Email      : avpleon@myseneca.ca
   Section    : NFF
*/

#ifndef SENECA_BARBARIAN_H
#define SENECA_BARBARIAN_H

#include <iostream>
#include <iomanip>
#include "characterTpl.h"
#include "abilities.h"
#include "weapons.h"

using namespace std;

namespace seneca {

    template <typename T, typename Ability_t, typename Weapon_t>
    class Barbarian : public CharacterTpl<T> {
    private:
        int m_baseAttack;
        int m_baseDefense;
        Ability_t m_ability;
        Weapon_t m_weapons[2];

    public:
        Barbarian(const char* name, int healthMax, int baseAttack, int baseDefense, Weapon_t primaryWeapon, Weapon_t secondaryWeapon);

        int getAttackAmnt() const;
        int getDefenseAmnt() const;
        Character* clone() const;
        void attack(Character* enemy);
        void takeDamage(int dmg);
    };

    // Implementation of Barbarian class methods

    template<typename T, typename Ability_t, typename Weapon_t>
    Barbarian<T, Ability_t, Weapon_t>::Barbarian(const char* name, int healthMax, int baseAttack, int baseDefense, Weapon_t primaryWeapon, Weapon_t secondaryWeapon) 
        : CharacterTpl<T>(name, healthMax), m_baseAttack(baseAttack), m_baseDefense(baseDefense), m_weapons{ primaryWeapon, secondaryWeapon }
    {
    }

    // Calculate attack amount
    template<typename T, typename Ability_t, typename Weapon_t>
    int Barbarian<T, Ability_t, Weapon_t>::getAttackAmnt() const
    {
        int firstWeaponDamage = static_cast<double>(m_weapons[0]);
        int secondWeaponDamage = static_cast<double>(m_weapons[1]);
        int damage = static_cast<int>(m_baseAttack + (firstWeaponDamage / 2.0) + (secondWeaponDamage / 2.0));
        return damage;
    }

    // Return defense amount
    template<typename T, typename Ability_t, typename Weapon_t>
    int Barbarian<T, Ability_t, Weapon_t>::getDefenseAmnt() const
    {
        return m_baseDefense;
    }

    // Create a clone of the Barbarian object
    template<typename T, typename Ability_t, typename Weapon_t>
    Character* Barbarian<T, Ability_t, Weapon_t>::clone() const
    {
        return new Barbarian(*this);
    }

    // Attack
    template<typename T, typename Ability_t, typename Weapon_t>
    void Barbarian<T, Ability_t, Weapon_t>::attack(Character* enemy)
    {
        std::string name = this->getName();
        std::string enemyName = enemy->getName();
        cout << name << " is attacking " << enemyName << "." << endl;

        m_ability.useAbility(this);

        int damage = getAttackAmnt();

        m_ability.transformDamageDealt(damage);

        cout << setw(4) << "" << "Barbarian deals " << damage << " melee damage!" << endl;

        enemy->takeDamage(damage);
    }

    // Take damage from attack
    template<typename T, typename Ability_t, typename Weapon_t>
    void Barbarian<T, Ability_t, Weapon_t>::takeDamage(int dmg)
    {
        std::string name = this->getName();

        cout << name << " is attacked for " << dmg << " damage." << endl;
        cout << setw(4) << "" << "Barbarian has a defense of " << m_baseDefense << ". " << "Reducing damage received." << endl;

        dmg -= m_baseDefense;
        dmg = std::max(dmg, 0);

        m_ability.transformDamageReceived(dmg);

        CharacterTpl<T>::takeDamage(dmg);
    }

}

#endif // SENECA_BARBARIAN_H
