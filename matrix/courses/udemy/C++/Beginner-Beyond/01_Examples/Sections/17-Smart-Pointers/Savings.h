#pragma once

#include "Account.h"

class Savings : public Account
{
  public:
    virtual ~Savings() override;
    virtual void withdraw(double amount) override;
    virtual void deposit(double) override;

    virtual void print(std::ostream& os) const override;
};