#include <iostream>
#include <vector>
#include "Pawn.h"

using std::vector;

int main()
{
    Object* objectPtr = new Object();
    Actor* actorPtr = new Actor();
    Pawn* pawnPtr = new Pawn();

    vector<Object*> ObjectVector{objectPtr, actorPtr, pawnPtr}; // Actor/Pawn is-a(n) Object

    for (unsigned int i = 0; i < ObjectVector.size(); i++)
    {
        ObjectVector.at(i)->BeginPlay();
    }

    delete objectPtr;
    delete actorPtr;
    delete pawnPtr;
    return 0;
}