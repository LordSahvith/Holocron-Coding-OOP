#pragma once

#include "Account.h"

class Trust : public Account
{
  public:
    virtual ~Trust() override;
    virtual void withdraw(double amount) override;
};