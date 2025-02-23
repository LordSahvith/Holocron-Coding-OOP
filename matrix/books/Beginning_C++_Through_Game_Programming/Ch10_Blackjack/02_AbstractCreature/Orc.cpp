// Orc Class

#include "Orc.h"
#include <iostream>

using std::cout;

Orc::Orc(int health) : Creature(health)
{
}

void Orc::Greet() const
{
    cout << "The orc grunts hello.\n";
}