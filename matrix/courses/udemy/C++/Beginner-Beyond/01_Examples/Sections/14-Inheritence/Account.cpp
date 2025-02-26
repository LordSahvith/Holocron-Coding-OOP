#include <iostream>
#include "Account.h"

Account::Account(double balanceValue, std::string nameValue) : balance{balanceValue}, name{nameValue}
{
}

Account::~Account()
{
}

void Account::deposit(double amount)
{
    balance += amount;
    std::cout << "Account deposit called with " << amount << std::endl;
}

void Account::withdraw(double amount)
{
    if (balance -= amount >= 0)
    {
        balance -= amount;
        std::cout << "Account withdraw called with " << amount << std::endl;
    }
    else
    {
        std::cout << "\nInsufficient funds\n";
    }
}