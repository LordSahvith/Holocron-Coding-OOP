#include <iostream>
#include "SavingsAccount.h"

SavingsAccount::SavingsAccount(double balanceValue, std::string nameValue, double interestValue)
    : Account(balanceValue, nameValue), interestRate{interestValue}
{
    std::cout << "\n*******************************\n";
    std::cout << "* Savings Account Constructor *";
    std::cout << "\n*******************************\n";
}

SavingsAccount::~SavingsAccount()
{
    std::cout << "\n******************************\n";
    std::cout << "* Savings Account Destructor *";
    std::cout << "\n******************************\n";
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