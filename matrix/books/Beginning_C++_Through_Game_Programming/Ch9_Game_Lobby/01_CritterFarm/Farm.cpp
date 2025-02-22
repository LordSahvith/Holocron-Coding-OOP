// Farm Class

#include "Farm.h"
#include "Critter.h"
#include <iostream>
#include <vector>

using namespace std;

Farm::Farm(int spaces)
{
    Critters.reserve(spaces);
}

void Farm::Add(const Critter& aCritter)
{
    Critters.push_back(aCritter);
}

void Farm::RollCall() const
{
    for (vector<Critter>::const_iterator iterator = Critters.begin(); iterator != Critters.end(); ++iterator)
    {
        cout << iterator->GetName() << " here.\n";
    }
}