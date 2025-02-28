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