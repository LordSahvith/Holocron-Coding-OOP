#pragma once

#include "Account.h"

class Checking : public Account
{
  public:
    virtual ~Checking();
    virtual void withdraw(double amount);
};