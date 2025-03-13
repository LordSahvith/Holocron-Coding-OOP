#include "../../00_std_lib_facilities.h"

int main()
{
    constexpr double cm_per_in{2.54};
    constexpr double in_per_ft{12.0};
    constexpr double cm_per_m{100.0};

    double sum{0};
    double smallestNum{0};
    double largestNum{0};

    double currentNum{0};
    string unit{' '};
    bool isFirstLoop{true};

    cout << "Please enter a length followed by a unit (in, ft, cm, m): ";

    while (cin >> currentNum >> unit)
    {
        double converted{0.0};

        if (isFirstLoop)
        {
            smallestNum = currentNum;
            isFirstLoop = false;
        }

        if (unit == "in")
        {
            double cm{cm_per_in * currentNum};
            converted = cm / cm_per_m;
            sum += converted;

            cout << currentNum << "in == " << cm << "cm" << endl;
        }
        else if (unit == "ft")
        {
            double in{in_per_ft * currentNum};
            double cm{cm_per_in * in};
            converted = cm / cm_per_m;
            sum += converted;

            cout << currentNum << "ft == " << in << "in" << endl;
        }
        else if (unit == "cm")
        {
            converted = currentNum / cm_per_m;
            sum += converted;
            cout << currentNum << "cm == " << currentNum / cm_per_in << "in" << endl;
        }
        else if (unit == "m")
        {
            converted = currentNum;
            sum += converted;
            cout << currentNum << "m == " << currentNum * cm_per_m << "cm" << endl;
        }
        else
        {
            cout << "Sorry, that unit is not available." << endl;
        }

        if (converted < smallestNum)
        {
            smallestNum = converted;
        }

        if (converted > largestNum)
        {
            largestNum = converted;
        }
    }

    cout << "The sum: " << sum << "m == " << sum * cm_per_m << "cm" << endl;
    cout << "The smallest number: " << smallestNum << "m" << endl;
    cout << "The largest number: " << largestNum << "m" << endl;
}