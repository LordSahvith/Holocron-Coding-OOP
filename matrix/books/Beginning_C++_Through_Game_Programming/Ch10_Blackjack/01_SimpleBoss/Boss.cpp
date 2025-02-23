// Enemy Class

#include "Boss.h"
#include <iostream>

using std::cout;

Boss::Boss()
{
    DamageMultiplier = 3;
}

void Boss::SpecialAttack() const
{
    cout << "Special Attack inflicts " << Damage * DamageMultiplier << " damage points!\n";
}