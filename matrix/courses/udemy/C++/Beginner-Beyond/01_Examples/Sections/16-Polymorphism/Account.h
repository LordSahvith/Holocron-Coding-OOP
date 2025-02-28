#pragma once

#include <string>

class Account
{
  public:
    virtual ~Account();
    virtual void withdraw(double amount);
};