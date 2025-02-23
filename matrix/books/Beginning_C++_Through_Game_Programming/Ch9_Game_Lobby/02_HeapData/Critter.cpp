// Critter Class

#include "Critter.h"
#include <iostream>
#include <string>

using std::cout;
using std::endl;

Critter::Critter(const string& name, int age)
{
    cout << "Constructor called\n";
    Name = new string(name);
    Age = age;
}

Critter::~Critter() // Destructor Definition
{
    cout << "Destructor called\n";
    delete Name;
}

Critter::Critter(const Critter& copy) // Copy Constructor Definition
{
    cout << "Copy Constructor called\n";
    Name = new string(*(copy.Name));
    Age = copy.Age;
}

// Critter& Critter::operator=(const Critter& copy) // Overloaded Assingment op def
// {
//     cout << "Overloaded Assignment Operator called\n";

//     if (this != &copy)
//     {
//         delete Name;
//         Name = new string(*(copy.Name));
//         Age = copy.Age;
//     }

//     return *this;
// }

void Critter::Greet() const
{
    cout << "I'm " << *Name << " and I'm " << Age << " years old.";
    cout << "&Name: " << &Name << endl;
}