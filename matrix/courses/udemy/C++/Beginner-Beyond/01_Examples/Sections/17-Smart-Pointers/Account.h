// Account Abstract Class
#pragma once

#include <string>
#include "PrintableInterface.h"

class Account : public I_Printable
{
  public:
    virtual ~Account();
    virtual void withdraw(double amount) = 0;
    virtual void deposit(double) = 0;
    virtual void print(std::ostream& os) const = 0;
};