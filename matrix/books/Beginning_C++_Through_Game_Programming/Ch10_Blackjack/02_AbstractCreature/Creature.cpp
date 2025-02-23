// Creature Abstract Class

#include "Creature.h"
#include <iostream>

using std::cout;
using std::endl;

Creature::Creature(int health)
{
    Health = health;
}

void Creature::DisplayHealth() const
{
    cout << "Health: " << Health << endl;
}