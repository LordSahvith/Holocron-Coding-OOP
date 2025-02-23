// Simple Boss 4.0
// Demonstrates inheritence, calling/overriding base member functions, calling member functions dynamically

#include <iostream>
#include "Boss.h"

using std::cout;
using std::endl;

int main()
{
    // cout << "Creating an enemy.\n";
    // Enemy Grunt;
    // Grunt.Taunt();
    // Grunt.Attack();

    // cout << "\nCreating a Boss.\n";
    // Boss BossMan;
    // BossMan.Taunt();
    // BossMan.Attack();
    // BossMan.SpecialAttack();

    cout << "Calling Attack() on Boss Object through pointer to Enemy:\n";
    Enemy* BadGuy = new Boss();
    BadGuy->Taunt();
    BadGuy->Attack();

    cout << "\n\nDeleting pointer to enemy:\n";
    delete BadGuy;
    BadGuy = 0;

    return 0;
}