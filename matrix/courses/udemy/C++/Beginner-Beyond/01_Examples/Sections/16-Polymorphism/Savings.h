#pragma once

#include "Account.h"

class Savings : public Account
{
  public:
    virtual ~Savings();
    virtual void withdraw(double amount);
};