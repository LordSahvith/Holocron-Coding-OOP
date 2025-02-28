#pragma once

#include "Account.h"

class Savings : public Account
{
  public:
    virtual ~Savings() override;
    virtual void withdraw(double amount) override;
    virtual void deposit(double) override;
};