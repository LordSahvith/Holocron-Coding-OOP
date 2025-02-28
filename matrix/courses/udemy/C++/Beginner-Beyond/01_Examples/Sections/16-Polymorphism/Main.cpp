#include <iostream>
#include <vector>
#include "Savings.h"
#include "Trust.h"
#include "Checking.h"

using namespace std;

void withdrawl(Account& account, double amount)
{
    account.withdraw(amount);
    cout << endl;
}

int main()
{
    cout << "\n======= Pointers =======\n";

    Account* pt2 = new Checking();
    Account* pt3 = new Savings();
    Account* pt4 = new Trust();

    pt2->withdraw(1000);
    pt3->withdraw(1000);
    pt4->withdraw(1000);

    delete pt2;
    delete pt3;
    delete pt4;

    cout << "\n======= References =======\n";

    cout << endl;

    Trust t;
    Account& tRef = t;
    tRef.withdraw(1000); // calls Trust::withdraw

    cout << endl;

    Savings a2;
    Checking a3;
    Trust a4;

    withdrawl(a2, 2000); // Savings::withdraw
    withdrawl(a3, 3000); // Checking::withdraw
    withdrawl(a4, 4000); // Trust::withdraw

    Account* account1 = new Checking();
    Account* account2 = new Savings();
    Account* account3 = new Trust();

    cout << "\n======= Vectors =======\n";

    cout << endl;

    // create vector of Base Classes with Derived classes
    // Polymorphism
    vector<Account*> Accounts{account1, account2};
    Accounts.push_back(account3);

    // loop over Accounts and call derived withdraw methods
    for (Account* account : Accounts)
    {
        account->withdraw(1000);
    }

    cout << endl;

    delete account1;
    cout << endl;
    delete account2;
    cout << endl;
    delete account3;
    cout << endl;

    return 0;
}