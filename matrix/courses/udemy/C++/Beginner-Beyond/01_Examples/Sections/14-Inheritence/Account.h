#pragma once

#include <string>

class Account
{
  public:
    void deposit(double amount);
    void withdraw(double amount);
    Account(double balanceValue = 0, std::string nameValue = "none");
    ~Account();

    double balance;
    std::string name;
};