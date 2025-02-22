// Critter Caretaker
// Simulates caring for a virtual pet

#include <iostream>
#include "Critter.h"

using namespace std;

int main()
{
    Critter MyCritter("Maui");

    int choice;
    do
    {
        MyCritter.GetStats();

        cout << "\nCritter Caretaker\n";
        cout << "0 - Quit\n";
        cout << "1 - Listen to your critter\n";
        cout << "2 - Feed your critter\n";
        cout << "3 - Play with your critter\n";

        cout << "\nChoice: ";
        cin >> choice;

        switch (choice)
        {
        case 0:
            cout << "Goodbye." << endl;
            break;
        case 1:
            MyCritter.Talk();
            break;
        case 2:
            MyCritter.Eat();
            break;
        case 3:
            MyCritter.Play();
            break;
        default:
            cout << "Sorry, but " << choice << " isn't a valid choice.\n";
        }
    } while (choice != 0);

    return 0;
}
