#pragma once

#include "Account.h"

class Trust : public Account
{
  public:
    virtual void withdraw(double amount);
};