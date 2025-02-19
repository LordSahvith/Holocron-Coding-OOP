// Die Roller
// Demonstrates generating random numbers

#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main()
{

    bool rollAgain = true;

    while (rollAgain)
    {
        srand(static_cast<unsigned int>(time(0))); // seed random number generator

        int randomNumber = rand();
        int die = (randomNumber % 6) + 1; // get a number between 1-6
        cout << "You rolled a " << die << endl;

        char choice;
        cout << "\nRoll again? (y/n): ";
        cin >> choice;

        if (choice == 'n')
        {
            rollAgain = false;
        }
    }

    return 0;
}