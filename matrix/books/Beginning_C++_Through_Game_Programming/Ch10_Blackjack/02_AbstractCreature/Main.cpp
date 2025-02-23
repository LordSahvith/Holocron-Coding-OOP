// Abstract Creature
// Demonstrates abstract classes

#include "Orc.h"

int main()
{
    Creature* MyCreature = new Orc();
    MyCreature->Greet();
    MyCreature->DisplayHealth();

    return 0;
}