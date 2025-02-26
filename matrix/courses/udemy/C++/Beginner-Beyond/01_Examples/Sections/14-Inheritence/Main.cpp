#include <iostream>
#include "SavingsAccount.h"

using namespace std;

int main()
{
    cout << "\n================ Account ================\n";

    Account Account1{};
    Account1.deposit(2500.0);
    Account1.withdraw(500.0);

    cout << endl;

    Account* AccountPtr1{nullptr};
    AccountPtr1 = new Account();
    AccountPtr1->deposit(5000.0);
    AccountPtr1->withdraw(900.0);
    delete AccountPtr1;

    cout << "\n================ Savings Account ================\n";

    SavingsAccount Savings{};
    Savings.deposit(5000.0);
    Savings.withdraw(400.0);

    cout << endl;

    {
        SavingsAccount Savings2{};
        Savings2.deposit(5000.0);
        Savings2.withdraw(400.0);
    }

    cout << endl;

    SavingsAccount* SavingsPtr{nullptr};
    SavingsPtr = new SavingsAccount(10000.0, "Savith", 4.4);
    SavingsPtr->withdraw(2000.0);
    delete SavingsPtr;

    return 0;
}