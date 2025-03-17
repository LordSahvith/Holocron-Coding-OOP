#include "../../../00_std_lib_facilities.h"

int main()
{
    int num1{0};
    string result{};

    cout << "Enter a number from 0-9: ";
    cin >> num1;

    switch (num1)
    {
        case 0:
            result = "zero";
            break;
        case 1:
            result = "one";
            break;
        case 2:
            result = "two";
            break;
        case 3:
            result = "three";
            break;
        case 4:
            result = "four";
            break;
        case 5:
            result = "five";
            break;
        case 6:
            result = "six";
            break;
        case 7:
            result = "seven";
            break;
        case 8:
            result = "eight";
            break;
        case 9:
            result = "nine";
            break;
        default:
            cout << "Sorry, that digit isn't excepted." << endl;
            break;
    }

    cout << result << " : " << num1 << endl;
}