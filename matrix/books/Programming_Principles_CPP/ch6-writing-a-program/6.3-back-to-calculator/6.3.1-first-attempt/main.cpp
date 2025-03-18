#include "../../../00_std_lib_facilities.h"

int main()
{
    cout << "Please enter expression (we can handle +, -, * and /)" << endl;
    cout << "add an x to end expression (e.g., 1+2*3x): ";
    int lval{0};
    int rval;
    cin >> lval;

    if (!cin)
    {
        error("no first operand");
    }

    for (char operation; cin >> operation;)
    {
        if (operation != 'x')
        {
            cin >> rval;
        }
        if (!cin)
        {
            error("no second operand");
        }

        switch (operation)
        {
            case '+':
                lval += rval;
                break;
            case '-':
                lval -= rval;
                break;
            case '*':
                lval *= rval;
                break;
            case '/':
                lval /= rval;
                break;
            default:
                cout << "Result: " << lval << endl;
                return 0;
        }
    }
    error("bad expression");
}