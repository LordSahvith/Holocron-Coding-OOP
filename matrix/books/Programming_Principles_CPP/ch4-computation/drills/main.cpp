#include "../../00_std_lib_facilities.h"

int main()
{
    constexpr double cm_per_m{100.0};

    double sum{0};
    double smallestNum{0};
    double largestNum{0};

    double currentNum{0};
    bool isFirstLoop{true};

    cout << "Please enter a length followed by a unit (m): ";

    while (cin >> currentNum)
    {
        sum += currentNum;

        cout << currentNum << "m == " << currentNum * cm_per_m << "cm" << endl;

        if (isFirstLoop)
        {
            smallestNum = currentNum;
            isFirstLoop = false;
        }

        if (currentNum < smallestNum)
        {
            smallestNum = currentNum;
        }

        if (currentNum > largestNum)
        {
            largestNum = currentNum;
        }
    }

    cout << "The sum: " << sum << "m == " << sum * cm_per_m << "cm" << endl;
    cout << "The smallest number: " << smallestNum << "m" << endl;
    cout << "The largest number: " << largestNum << "m" << endl;
}