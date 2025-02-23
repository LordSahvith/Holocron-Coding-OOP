// Enemy Class

#include "Enemy.h"
#include <iostream>

using std::cout;

Enemy::Enemy(int damage)
{
    Damage = damage;
}

void Enemy::Taunt() const
{
    cout << "Enemy: I will fight you!\n";
}

void Enemy::Attack() const
{
    cout << "Attack inflicts " << Damage << " damage points!\n";
}