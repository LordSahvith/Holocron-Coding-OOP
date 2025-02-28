#include <iostream>
#include "Account.h"

Account::~Account()
{
    std::cout << "Account Destructor." << std::endl;
}