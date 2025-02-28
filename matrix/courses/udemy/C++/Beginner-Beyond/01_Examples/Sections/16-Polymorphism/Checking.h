#pragma once

#include "Account.h"

class Checking : public Account
{
  public:
    virtual void withdraw(double amount);
};