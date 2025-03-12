#include "../../../../00_std_lib_facilities.h"

int main()
{
    string string1{0};
    string string2{0};
    string string3{0};

    cout << "Enter 3 integers: ";
    cin >> string1 >> string2 >> string3;

    if (string1 > string2)
    {
        string temp{string1};
        string1 = string2;
        string2 = temp;
    }

    if (string1 > string3)
    {
        string temp{string1};
        string1 = string3;
        string3 = temp;
    }

    if (string2 > string3)
    {
        string temp{string2};
        string2 = string3;
        string3 = temp;
    }

    cout << string1 << ", ";
    cout << string2 << ", ";
    cout << string3 << endl;
}