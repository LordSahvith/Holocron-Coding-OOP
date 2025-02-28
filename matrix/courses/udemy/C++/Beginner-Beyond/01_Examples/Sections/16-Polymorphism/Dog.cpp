#include <iostream>
#include "Dog.h"

Dog::~Dog()
{
    std::cout << "Dog Destructor." << std::endl;
}

void Dog::print(std::ostream& os) const
{
    os << "You're wel....bark bark!";
}