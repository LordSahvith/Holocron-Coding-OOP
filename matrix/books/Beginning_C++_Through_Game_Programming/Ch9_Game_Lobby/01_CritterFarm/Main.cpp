// Critter Farm
// Demonstrates object containment

#include <iostream>
#include "Critter.h"
#include "Farm.h"

using namespace std;

int main()
{
    Critter MyCritter("Maui");
    cout << "My critter's name is " << MyCritter.GetName() << endl;

    cout << "\nCreating critter farm.\n";
    int numCritters{3};
    Farm MyFarm(numCritters);

    cout << "\nAdding " << numCritters << " critters to the farm.\n";
    MyFarm.Add(Critter("Maui"));
    MyFarm.Add(Critter("Everest"));
    MyFarm.Add(Critter("Bob"));

    cout << "\nCalling Roll...\n";
    MyFarm.RollCall();

    return 0;
}