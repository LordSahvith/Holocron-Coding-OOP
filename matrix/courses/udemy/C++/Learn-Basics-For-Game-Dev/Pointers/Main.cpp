#include <iostream>
#include <string>

using namespace std;

struct Container
{
    string Name;

    int X;
    int Y;
    int Z;
};

int main()
{
    // Primitive types
    int damage = 100;

    int* damagePtr = &damage;
    cout << "damagePtr: " << damagePtr << endl;   // pointers print addresses
    cout << "*damagePtr: " << *damagePtr << endl; // must dereference (*) for value in address's location

    int newDamage = 50;

    damagePtr = &newDamage;
    cout << "damagePtr: " << damagePtr << endl;   // now points to a different address (newDamage's address)
    cout << "*damagePtr: " << *damagePtr << endl; // must dereference (*) for value in address's location

    // Arrays
    int numbers[]{0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    cout << "nubmers: " << numbers << endl;   // array names are pointers to the first index numbers[0]
    cout << "*nubmers: " << *numbers << endl; // Dereference to get value

    int* NumPtr = numbers;                  // Don't need the '&' since array names are pointers to the first index
    cout << "NumPtr: " << NumPtr << endl;   // prints the same address as numbers on line 20
    cout << "*NumPtr: " << *NumPtr << endl; // prints the same value as *numbers on line 21

    NumPtr++;                               // increase pointer by 1 - next index in sequence
    cout << "NumPtr: " << NumPtr << endl;   // prints the address from numbers[1] in this example
    cout << "*NumPtr: " << *NumPtr << endl; // prints the value from numbers[1] in this example

    // Structs
    Container container{"Savith", 5, 6, 7};

    Container* containerPtr = &container;
    cout << "Name: " << (*containerPtr).Name << endl; // dereference then access property
    cout << "Name: " << containerPtr->Name << endl;   // same as above, just cleaner

    return 0;
}