#include <iostream>
#include "SavingsAccount.h"

SavingsAccount::SavingsAccount() : interestRate{3.0}
{
}

SavingsAccount::~SavingsAccount()
{
}

void SavingsAccount::deposit(double amount)
{
    balance += amount;
    std::cout << "Savings Account deposit called with " << amount << std::endl;
}

void SavingsAccount::withdraw(double amount)
{
    if (balance -= amount >= 0)
    {
        balance -= amount;
        std::cout << "Savings Account withdraw called with " << amount << std::endl;
    }
    else
    {
        std::cout << "\nInsufficient funds\n";
    }
}