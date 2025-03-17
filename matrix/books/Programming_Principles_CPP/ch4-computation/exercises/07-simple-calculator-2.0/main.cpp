#include "../../../00_std_lib_facilities.h"

int convertToInt(string number)
{
    if (number == "0" || number == "zero")
    {
        return 0;
    }
    else if (number == "1" || number == "one")
    {
        return 1;
    }
    else if (number == "2" || number == "two")
    {
        return 2;
    }
    else if (number == "3" || number == "three")
    {
        return 3;
    }
    else if (number == "4" || number == "four")
    {
        return 4;
    }
    else if (number == "5" || number == "five")
    {
        return 5;
    }
    else if (number == "6" || number == "six")
    {
        return 6;
    }
    else if (number == "7" || number == "seven")
    {
        return 7;
    }
    else if (number == "8" || number == "eight")
    {
        return 8;
    }
    else if (number == "9" || number == "nine")
    {
        return 9;
    }
    else
    {
        cout << "Sorry, that digit isn't excepted." << endl;
        return -1;
    }
}

int main()
{
    string num1{};
    int realNum1{0};
    string num2{};
    int realNum2{0};
    string result{};
    int realResult{0};
    char operand;

    cout << "Enter 2 numbers followed by operand (+, -, *, /): ";
    cin >> num1 >> num2 >> operand;

    realNum1 = convertToInt(num1);
    realNum2 = convertToInt(num2);

    switch (operand)
    {
        case '+':
            realResult = realNum1 + realNum2;
            break;
        case '-':
            realResult = realNum1 - realNum2;
            break;
        case '*':
            realResult = realNum1 * realNum2;
            break;
        case '/':
            realResult = realNum1 / realNum2;
            break;
        default:
            cout << "Sorry, that operand isn't supported." << endl;
            break;
    }

    cout << "Result: " << realResult << endl;
}