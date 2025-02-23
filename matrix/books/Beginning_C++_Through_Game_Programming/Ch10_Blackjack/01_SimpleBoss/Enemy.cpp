// Enemy Class

#include "Enemy.h"
#include <iostream>

using std::cout;

Enemy::Enemy(int damage)
{
    Damage = new int(damage);
}

Enemy::~Enemy()
{
    cout << "Enemy Destructor: deleting Damage.\n";
    delete Damage;
    Damage = 0; // nullptr
}

void Enemy::Taunt() const
{
    cout << "Enemy: I will fight you!\n";
}

void Enemy::Attack() const
{
    cout << "Attack inflicts " << *Damage << " damage points!\n";
}