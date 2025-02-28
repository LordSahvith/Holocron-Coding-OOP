#include <iostream>
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

    cout << endl;

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

    return 0;
}