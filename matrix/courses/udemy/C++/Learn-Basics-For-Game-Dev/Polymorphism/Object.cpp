#include <iostream>
#include "Object.h"

void Object::BeginPlay()
{
    std::cout << "Object BeginPlay() called. \n";
}

Object::~Object()
{
    std::cout << "Object Destructor called. \n";
}