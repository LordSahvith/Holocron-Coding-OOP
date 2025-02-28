#pragma once

#include "Account.h"

class Savings : public Account
{
  public:
    virtual void withdraw(double amount);
};