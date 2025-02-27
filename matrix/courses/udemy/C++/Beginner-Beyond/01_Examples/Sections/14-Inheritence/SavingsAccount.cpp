#include <iostream>
#include "SavingsAccount.h"

SavingsAccount::SavingsAccount(double balanceValue, std::string nameValue, double interestValue)
    : Account(balanceValue, nameValue), interestRate{interestValue}
{
}