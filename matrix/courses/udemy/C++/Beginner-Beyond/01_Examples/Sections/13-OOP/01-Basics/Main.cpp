// Basic Classes and Objects

#include <iostream>
#include "Account.h"
#include "Player.h"

using std::cout;
using std::endl;

void AccountExample();

int main()
{
    AccountExample();

    Player Default;
    Player Savith{"Savith"};
    Player BadGuy{"Bad Guy", 100, 44};
    Player TwoGuy{"Two Args", 120};

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