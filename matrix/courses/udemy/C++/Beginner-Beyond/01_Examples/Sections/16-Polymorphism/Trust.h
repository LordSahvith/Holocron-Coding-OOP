#pragma once

#include "Account.h"

class Trust : public Account
{
  public:
    virtual ~Trust();
    virtual void withdraw(double amount);
};