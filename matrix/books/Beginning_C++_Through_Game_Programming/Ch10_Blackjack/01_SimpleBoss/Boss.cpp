// Enemy Class

#include "Boss.h"
#include <iostream>

using std::cout;

Boss::Boss(int damage, int damageMultiplier)
{
    Damage = &damage;
    DamageMultiplier = new int(damageMultiplier);
}

Boss::~Boss()
{
    cout << "Boss Destructor: deleting DamageMultiplier.\n";
    delete DamageMultiplier;
    DamageMultiplier = 0; // nullptr
}

void Boss::Taunt() const
{
    cout << "Boss: I will destroy you utterly and compltely!\n";
}

void Boss::Attack() const
{
    cout << "A boss attacks and inflicts " << *Damage << " damage points!\n";
    cout << "**Then laughs a deep rasping coughing sound.\n";
}

void Boss::SpecialAttack() const
{
    cout << "Boss: ready for my special attack?!\n";
    cout << "Special Attack inflicts " << (*Damage) * (*DamageMultiplier) << " damage points!\n";
}