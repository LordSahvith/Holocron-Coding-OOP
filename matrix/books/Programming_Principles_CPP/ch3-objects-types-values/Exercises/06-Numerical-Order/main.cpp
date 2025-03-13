#include "../../../../00_std_lib_facilities.h"

int main()
{
    int num1{0};
    int num2{0};
    int num3{0};

    cout << "Enter 3 integers: ";
    cin >> num1 >> num2 >> num3;

    if (num1 > num2)
    {
        int temp{num1};
        num1 = num2;
        num2 = temp;
    }

    if (num1 > num3)
    {
        int temp{num1};
        num1 = num3;
        num3 = temp;
    }

    if (num2 > num3)
    {
        int temp{num2};
        num2 = num3;
        num3 = temp;
    }

    cout << num1 << ", ";
    cout << num2 << ", ";
    cout << num3 << endl;
}