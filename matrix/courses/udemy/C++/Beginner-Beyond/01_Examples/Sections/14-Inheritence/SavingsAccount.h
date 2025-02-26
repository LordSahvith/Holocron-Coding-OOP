#pragma once

#include "Account.h"

class SavingsAccount : public Account
{
  public:
    SavingsAccount(double balanceValue = 0, std::string nameValue = "none", double interestValue = 3.0);
    ~SavingsAccount();
    void deposit(double amount);
    void withdraw(double amount);

    double interestRate;
};