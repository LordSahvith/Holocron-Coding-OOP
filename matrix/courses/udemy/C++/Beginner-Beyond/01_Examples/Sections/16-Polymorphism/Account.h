// Account Abstract Class
#pragma once

#include <string>

class Account
{
  public:
    virtual ~Account() {};
    virtual void withdraw(double amount) = 0;
    virtual void deposit(double) = 0;
};