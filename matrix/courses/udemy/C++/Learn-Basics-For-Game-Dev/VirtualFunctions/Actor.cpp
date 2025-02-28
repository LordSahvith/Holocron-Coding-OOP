#include <iostream>
#include "Actor.h"

void Actor::BeginPlay()
{
    std::cout << "Actor BeginPlay() called. \n";
    Object::BeginPlay();
}

Actor::~Actor()
{
    std::cout << "Actor Destructor called. \n";
}