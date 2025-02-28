#pragma once

#include "Account.h"

class Trust : public Account
{
  public:
    virtual ~Trust() override;
    virtual void withdraw(double amount) override;
    virtual void deposit(double) override;

    virtual void print(std::ostream& os) const override;
};