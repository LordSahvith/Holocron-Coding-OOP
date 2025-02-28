// Dog Class
#pragma once

#include <string>
#include "PrintableInterface.h"

class Dog : public I_Printable
{
  public:
    virtual ~Dog();
    virtual void print(std::ostream& os) const override;
};