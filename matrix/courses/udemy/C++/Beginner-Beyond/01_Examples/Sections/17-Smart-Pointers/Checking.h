#pragma once

#include "Account.h"

class Checking : public Account
{
  public:
    virtual ~Checking() override;
    virtual void withdraw(double amount) override;
    virtual void deposit(double) override;

    virtual void print(std::ostream& os) const override;
};