// Critter Class

#include "Critter.h"

Critter::Critter(const string& name)
{
    CritterName = name;
}

string Critter::GetName() const
{
    return CritterName;
}