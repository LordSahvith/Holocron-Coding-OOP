#include "../../00_std_lib_facilities.h"

int main()
{
    constexpr double cm_per_in{2.54};
    constexpr double in_per_ft{12.0};
    constexpr double cm_per_m{100.0};

    double currentNum{0};
    string unit{' '};

    cout << "Please enter a length followed by a unit (in, ft, cm, m): ";

    while (cin >> currentNum >> unit)
    {
        if (unit == "in")
        {
            cout << currentNum << "in == " << cm_per_in * currentNum << "cm" << endl;
        }
        else if (unit == "ft")
        {
            cout << currentNum << "ft == " << in_per_ft * currentNum << "in" << endl;
        }
        else if (unit == "cm")
        {
            cout << currentNum << "cm == " << currentNum / cm_per_in << "in" << endl;
        }
        else if (unit == "m")
        {
            cout << currentNum << "m == " << currentNum * cm_per_m << "cm" << endl;
        }
    }
}