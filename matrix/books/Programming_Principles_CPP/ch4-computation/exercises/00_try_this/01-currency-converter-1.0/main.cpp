#include "../../../../00_std_lib_facilities.h"

int main()
{
    constexpr double yenPerDollar{147.93};
    constexpr double kronerPerDollar{10.67};
    constexpr double poundsPerDollar{0.77};
    double amount{1.0};

    char unit{' '}; // a space is not a unit
    cout << "Please enter an amount followed by a unit (y, k, p): ";
    cin >> amount >> unit;

    switch (unit)
    {
        case 'y':
            cout << amount << " yen == " << amount / yenPerDollar << " dollar" << endl;
            break;
        case 'k':
            cout << amount << " kroner == " << amount / kronerPerDollar << " dollar" << endl;
            break;
        case 'p':
            cout << amount << " pounds == " << amount / poundsPerDollar << " dollar" << endl;
            break;
        default:
            cout << "Sorry, I don't know a unit called '" << unit << "'" << endl;
            break;
    }
}