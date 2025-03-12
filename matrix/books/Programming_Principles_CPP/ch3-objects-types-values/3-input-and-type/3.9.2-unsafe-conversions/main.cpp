#include <iostream>

using namespace std;

int main()
{
    int a = 20000;
    char c = a; // try to squeeze a large int into a small char
    int b = c;
    if (a != b)
    {
        cout << "oops!: " << a << " != " << b << "\n";
    }
    else
    {
        cout << "Wow! We have a large characters.\n";
    }

    double d = 0;
    while (cin >> d) // repeat while we have type in numbers
    {
        int i = d;  // try to squeeze a double into an int
        char c = i; // try to squeeze an int into a char
        int i2 = c; // get the integer value of the character
        cout << "d == " << d << endl;
        cout << " i == " << i << endl;
        cout << " i2 == " << i2 << endl;
        cout << " char(" << c << ")" << endl;
    }
}