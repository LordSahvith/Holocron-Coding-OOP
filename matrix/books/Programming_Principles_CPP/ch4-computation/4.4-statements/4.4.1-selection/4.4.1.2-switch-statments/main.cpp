#include "../../../../00_std_lib_facilities.h"

int main()
{
    constexpr double cm_per_inch{2.54};
    double length{1.0};

    char unit{' '}; // a space is not a unit
    cout << "Please enter a length followed by a unit (c or i): ";
    cin >> length >> unit;

    switch (unit)
    {
        case 'i':
            cout << length << "in == " << cm_per_inch * length << "cm" << endl;
            break;
        case 'c':
            cout << length << "cm == " << length / cm_per_inch << "in" << endl;
            break;
        default:
            cout << "Sorry, I don't know a unit called '" << unit << "'" << endl;
            break;
    }
}