#include "Critter.h"
#include <string>

using std::cout;
using std::endl;

Critter::Critter(string newName, int hunger, int boredom)
{
    CritterName = newName;
    Hunger = hunger;
    Boredom = boredom;
}

inline int Critter::GetMood() const
{
    return (Hunger + Boredom);
}

void Critter::PassTime(int time)
{
    Hunger += time;
    Boredom += time;
}

void Critter::Talk()
{
    cout << "I'm a critter and I feel ";
    int mood = GetMood();

    if (mood > 15)
    {
        cout << "mad.\n";
    }
    else if (mood > 10)
    {
        cout << "frustrated.\n";
    }
    else if (mood > 5)
    {
        cout << "okay.\n";
    }
    else
    {
        cout << "happy.\n";
    }

    PassTime();
}

void Critter::Eat(int food)
{
    cout << "eating..." << endl;

    Hunger -= food;

    if (Hunger < 0)
    {
        Hunger = 0;
    }

    PassTime();
}

void Critter::Play(int fun)
{
    cout << "playing...." << endl;

    Boredom -= fun;

    if (Boredom < 0)
    {
        Boredom = 0;
    }

    PassTime();
}

string Critter::GetName() const
{
    return CritterName;
}

void Critter::GetStats() const
{
    cout << "Name: " << CritterName << endl;
    cout << "Hunger: " << Hunger << endl;
    cout << "Boredom: " << Boredom << endl;
}