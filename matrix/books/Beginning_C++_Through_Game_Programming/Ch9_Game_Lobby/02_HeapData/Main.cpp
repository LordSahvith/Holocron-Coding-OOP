// Heap Data
// Demonstrates an object with a dynamically allolcated data member

#include <iostream>
#include "Critter.h"

using namespace std;

void testDestructor();
void testCopyConstructor(Critter copy);
void testAssingmentOp();

int main()
{
    testDestructor();
    cout << endl;

    Critter MyCritter("Maui", 4);
    MyCritter.Greet();
    testCopyConstructor(MyCritter);
    MyCritter.Greet();
    cout << endl;

    // testAssingmentOp();

    return 0;
}

void testDestructor()
{
    Critter toDestroy("Rover", 3);
    toDestroy.Greet();
}

void testCopyConstructor(Critter copy)
{
    copy.Greet();
}

void testAssingmentOp()
{
    Critter Critter1("Critter 1", 7);
    Critter Critter2("Critter 2", 9);
    Critter1 = Critter2;
    Critter1.Greet();
    Critter2.Greet();
    cout << endl;

    Critter Critter3("Critter", 11);
    Critter3 = Critter3;
    Critter3.Greet();
}