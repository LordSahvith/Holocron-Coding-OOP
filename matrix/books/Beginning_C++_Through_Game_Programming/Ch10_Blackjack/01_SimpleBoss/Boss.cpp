// Enemy Class

#include "Boss.h"
#include <iostream>

using std::cout;

Boss::Boss(int damage, int damageMultiplier)
{
    Damage = damage;
    DamageMultiplier = damageMultiplier;
}

void Boss::Taunt() const
{
    cout << "Boss: I will destroy you utterly and compltely!\n";
}

void Boss::Attack() const
{
    Enemy::Attack();
    cout << " and laughs a deep rasping coughing sound.\n";
}

void Boss::SpecialAttack() const
{
    cout << "Boss: ready for my special attack?!\n";
    cout << "Special Attack inflicts " << Damage * DamageMultiplier << " damage points!\n";
}