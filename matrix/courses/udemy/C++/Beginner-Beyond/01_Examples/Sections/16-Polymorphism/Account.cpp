#include <iostream>
#include "Account.h"

Account::~Account()
{
    std::cout << "Account Destructor." << std::endl;
}

void Account::withdraw(double amount)
{
    std::cout << "Account Withdraw." << std::endl;
}

void Account::deposit(double amount)
{
    std::cout << "Account Deposit." << std::endl;
}

void Account::print(std::ostream& os) const
{
    os << "Account Display.";
}