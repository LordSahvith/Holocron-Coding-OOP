#include "../../00_std_lib_facilities.h"

int main()
{
    double num1{0};
    double num2{0};

    while (cin >> num1 >> num2)
    {
        if (num1 > num2)
        {
            cout << "the smaller number is: " << num2 << endl;
            cout << "the larger number is: " << num1 << endl;

            if (num1 - num2 <= 1.0 / 100)
            {
                cout << "the numbers are almost equal" << endl;
            }
        }
        else if (num1 == num2)
        {
            cout << "the numbers are equal" << endl;
        }
        else
        {
            cout << "the smaller number is: " << num1 << endl;
            cout << "the larger number is: " << num2 << endl;

            if (num2 - num1 <= 1.0 / 100)
            {
                cout << "the numbers are almost equal" << endl;
            }
        }
    }
}