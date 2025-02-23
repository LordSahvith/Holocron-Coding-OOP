// Simple Boss 4.0
// Demonstrates inheritence, calling/overriding base member functions, calling member functions dynamically

#include <iostream>
#include "Boss.h"

using std::cout;
using std::endl;

int main()
{
    cout << "Creating an enemy.\n";
    Enemy Grunt;
    Grunt.Taunt();
    Grunt.Attack();

    cout << "\nCreating a Boss.\n";
    Boss BossMan;
    BossMan.Taunt();
    BossMan.Attack();
    BossMan.SpecialAttack();

    return 0;
}