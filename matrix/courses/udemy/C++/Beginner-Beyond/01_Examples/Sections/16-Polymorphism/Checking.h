#pragma once

#include "Account.h"

class Checking : public Account
{
  public:
    virtual ~Checking() override;
    virtual void withdraw(double amount) override;
    virtual void deposit(double) override;
};