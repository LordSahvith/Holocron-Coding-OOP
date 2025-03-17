#include "../../../00_std_lib_facilities.h"

int main()
{
    double num1{0.0};
    double num2{0.0};
    double result{0.0};
    char operand;

    cout << "Enter 2 numbers followed by operand (+, -, *, /): ";
    cin >> num1 >> num2 >> operand;

    switch (operand)
    {
        case '+':
            result = num1 + num2;
            break;
        case '-':
            result = num1 - num2;
            break;
        case '*':
            result = num1 * num2;
            break;
        case '/':
            result = num1 / num2;
            break;
        default:
            cout << "Sorry, that operand isn't supported." << endl;
            break;
    }

    cout << "Result: " << result << endl;
}