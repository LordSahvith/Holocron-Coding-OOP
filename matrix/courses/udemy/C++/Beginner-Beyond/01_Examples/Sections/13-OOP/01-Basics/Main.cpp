// Basic Classes and Objects

#include <iostream>
#include "Account.h"
#include "Player.h"

using std::cout;
using std::endl;

void AccountExample();
void DisplayPlayer(Player Player);
void DisplayPlayerCount();

int main()
{
    AccountExample();

    DisplayPlayerCount();

    Player Default;
    DisplayPlayer(Default);

    Player Savith{"Savith"};

    Player BadGuy{"Bad Guy", 100, 44};
    Player BadGuyCopy(BadGuy);

    Player TwoGuy{"Two Args", 120};

    DisplayPlayerCount();

    return 0;
}

void AccountExample()
{
    Account SavithAccount;
    SavithAccount.SetName("Savith");
    SavithAccount.SetBalance(1000.0);

    if (SavithAccount.Deposit(200.0))
    {
        cout << "Deposit OK." << endl;
    }
    else
    {
        cout << "Deposit error." << endl;
    }

    if (SavithAccount.Withdraw(500.0))
    {
        cout << "Withdrawl OK." << endl;
    }
    else
    {
        cout << "Insuffient funds." << endl;
    }

    if (SavithAccount.Withdraw(1500.0))
    {
        cout << "Withdrawl OK." << endl;
    }
    else
    {
        cout << "Insuffient funds." << endl;
    }

    cout << "\n================================" << endl;
}


void DisplayPlayer(Player Player)
{
    std::cout << "Name: " << Player.GetName() << std::endl;
    std::cout << "Health: " << Player.GetHealth() << std::endl;
    std::cout << "XP: " << Player.GetXP() << std::endl;
}

void DisplayPlayerCount()
{
    cout << "Active Players: " << Player::GetPlayerCount() << endl;
}