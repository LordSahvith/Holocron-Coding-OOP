#include <iostream>
#include "Account.h"

Account::Account(double balanceValue, std::string nameValue) : balance{balanceValue}, name{nameValue}
{
}

void Account::deposit(double amount)
{
    balance += amount;
    std::cout << name << " Account deposit called with " << amount << std::endl;
}

void Account::withdraw(double amount)
{
    if (balance -= amount >= 0)
    {
        balance -= amount;
        std::cout << name << " Account withdraw called with " << amount << std::endl;
    }
    else
    {
        std::cout << "Insufficient funds\n";
    }
}