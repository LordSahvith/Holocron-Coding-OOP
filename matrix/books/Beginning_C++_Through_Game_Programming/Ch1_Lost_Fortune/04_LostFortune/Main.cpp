// Lost Fortune
// A personalized adventure

#include <iostream>
#include <string>

using std::cin;
using std::cout;
using std::endl;
using std::string;

int main()
{
    const int GOLD_PIECES = 3;
    int adventurers, killed, survivors;
    string leader;

    // get the information
    cout << "Welcome to Lost Fortune\n\n";
    cout << "Please enter the following for your personalized adventure\n";

    cout << "Enter a number: ";
    cin >> adventurers;

    cout << "Enter a number, smaller than the first: ";
    cin >> killed;

    survivors = adventurers - killed;

    cout << "Enter your last name: ";
    cin >> leader;

    // tell the story
    cout << "\nA brave group of " << adventurers << " set out on a quest ";
    cout << "-- in search of the lost treasure of the Ancient Dwarves.";
    cout << "The group was ld by that legendary rouge, " << leader << ".\n";
    cout << "Along the way, a band of marauding ogres ambushed the party.";
    cout << "All fought bravely under the command of " << leader;
    cout << ", and the ogre were defeated, but at a cost.\n";
    cout << "Of the adventurers, " << killed << " were vanquished ";
    cout << "leaving just " << survivors << " in the group.\n";

    cout << "\nThe party was about to give up all hope. ";
    cout << "But while laying the deceased to rest, ";
    cout << "they stumbled upon the buried fortune.\n";
    cout << "So the adventurers split " << GOLD_PIECES << " gold pieces. ";
    cout << "Each getting " << (GOLD_PIECES / survivors) << " pieces, ";
    cout << "except " << leader << " of course, he kept the remaining ";
    cout << (GOLD_PIECES % survivors) << " pieces as they should.\n\n";

    return 0;
}