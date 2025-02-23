// Enemy Class

#include "Enemy.h"
#include <iostream>

using std::cout;

Enemy::Enemy()
{
    Damage = 10;
}

void Enemy::Attack() const
{
    cout << "Attack inflicts " << Damage << " damage points!\n";
}