#pragma once

#include <string>

class Account
{
  private:
    // attributes
    std::string Name;
    double Balance;

  public:
    // methods
    std::string GetName();
    void SetName(std::string name);
    void SetBalance(double amount);
    bool Deposit(double amount);
    bool Withdraw(double amount);
};