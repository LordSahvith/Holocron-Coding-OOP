// Hero's Inventory 2.0
// Demonstrates vectors

#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main()
{
    vector<string> inventory;
    inventory.push_back("sword");
    inventory.push_back("armor");
    inventory.push_back("shield");

    cout << "\n\nYou have " << inventory.size() << " items.\n";

    cout << "Your items:\n";
    for (string item : inventory)
    {
        cout << " - " << item << endl;
    }

    cout << "\nYou trade your " << inventory[0] << " for a battle axe.";
    inventory[0] = "battle axe";
    cout << "\nYour items:\n";
    for (string item : inventory)
    {
        cout << " - " << item << endl;
    }

    cout << "\nThe item name '" << inventory[0] << "' has ";
    cout << inventory[0].size() << " letters in it\n";

    cout << "\nYou find a healing potion.";
    inventory.push_back("healing potion");

    cout << "\nYour items:\n";
    for (string item : inventory)
    {
        cout << " - " << item << endl;
    }

    cout << "\nYou survive a gruesome battle with an Orc pack.";
    cout << "\nYour sheild was broken in battle and you used";
    cout << "\nyour healing potion to mend your wounds.\n";

    inventory.pop_back(); // healing potion
    inventory.pop_back(); // shield

    cout << "\nYour items:\n";
    for (string item : inventory)
    {
        cout << " - " << item << endl;
    }

    cout << "\nThen has luck has it, you were robbed by a theif in the night...";
    inventory.clear();

    cout << "\nYour items:\n";
    if (inventory.empty())
    {
        cout << "You have no items." << endl;
    }

    return 0;
}