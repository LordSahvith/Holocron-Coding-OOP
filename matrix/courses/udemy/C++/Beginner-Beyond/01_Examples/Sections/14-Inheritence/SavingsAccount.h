#pragma once

#include "Account.h"

class SavingsAccount : public Account
{
  public:
    SavingsAccount(double balanceValue = 0, std::string nameValue = "Savings", double interestValue = 3.0);

    double interestRate;
};