#include <iostream>

using namespace std;

int age {18}; // Global Variable

int main()
{
    int age {21}; // local variable - this takes precedence

    cout << age << endl;

    return 0;
}