#include <iostream>

using namespace std;

int main()
{
    int MaxInt {2147483647};
    cout << "int: " << sizeof(int) << endl;
    cout << "int: " << INT_MAX << endl;
    cout << "int: " << sizeof(MaxInt) << endl;

    return 0;
}