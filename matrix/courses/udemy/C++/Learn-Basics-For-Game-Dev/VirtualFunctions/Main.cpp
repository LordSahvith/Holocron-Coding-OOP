#include <iostream>
#include "Object.h"
#include "Actor.h"

int main()
{
    Object* obj = new Object();
    obj->BeginPlay();

    Actor* actor = new Actor();
    actor->BeginPlay();

    delete obj;
    delete actor;
    return 0;
}