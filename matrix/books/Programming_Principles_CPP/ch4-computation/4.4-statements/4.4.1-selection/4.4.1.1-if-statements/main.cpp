#include "../../../../00_std_lib_facilities.h"

int main()
{
    int a{0};
    int b{0};
    cout << "Please enter two integers: ";
    cin >> a >> b;

    if (a < b)
    {
        cout << "max(" << a << ", " << b << ") is " << b << endl;
    }
    else
    {
        cout << "max(" << a << ", " << b << ") is " << a << endl;
    }

    // convert from inches to centimeters anc vice versa
    // a suffix 'i' or 'c' indicates the unit of the input
    // any other suffix is an error

    constexpr double cm_per_inch{2.54};
    double length{1.0};

    char unit{' '}; // a space is not a unit
    cout << "Please enter a length followed by a unit (c or i): ";
    cin >> length >> unit;

    if (unit == 'i')
    {
        cout << length << "in == " << cm_per_inch * length << "cm" << endl;
    }
    else if (unit == 'c')
    {
        cout << length << "cm == " << length / cm_per_inch << "in" << endl;
    }
    else {
        cout << "Sorry, I don't know a unit called '" << unit << "'" << endl;
    }
}