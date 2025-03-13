#include "../../00_std_lib_facilities.h"

int main()
{
    constexpr double cm_per_in{2.54};
    constexpr double in_per_ft{12.0};
    constexpr double cm_per_m{100.0};

    double sumInMeters{0};
    double smallestNum{0};
    double largestNum{0};
    vector<double> convertedMetersVec{};

    double currentNum{0};
    string unit{' '};
    bool isFirstLoop{true};

    cout << "Please enter a length followed by a unit (in, ft, cm, m): ";

    double convertedToMeters{0.0};

    while (cin >> currentNum >> unit)
    {
        // set smallestNum on first iteration
        if (isFirstLoop)
        {
            smallestNum = currentNum;
            isFirstLoop = false;
        }

        // Handle Conversions
        if (unit == "in")
        {
            double cm{cm_per_in * currentNum};
            convertedToMeters = cm / cm_per_m;

            cout << currentNum << "in == " << cm << "cm" << endl;
        }
        else if (unit == "ft")
        {
            double in{in_per_ft * currentNum};
            double cm{cm_per_in * in};
            convertedToMeters = cm / cm_per_m;

            cout << currentNum << "ft == " << in << "in" << endl;
        }
        else if (unit == "cm")
        {
            convertedToMeters = currentNum / cm_per_m;
            cout << currentNum << "cm == " << currentNum / cm_per_in << "in" << endl;
        }
        else if (unit == "m")
        {
            convertedToMeters = currentNum;
            cout << currentNum << "m == " << currentNum * cm_per_m << "cm" << endl;
        }
        else
        {
            cout << "Sorry, that unit is not available." << endl;
        }

        sumInMeters += convertedToMeters;
        convertedMetersVec.push_back(convertedToMeters);

        // Get Smallest & Largest Numbers
        if (convertedToMeters < smallestNum)
        {
            smallestNum = convertedToMeters;
        }

        if (convertedToMeters > largestNum)
        {
            largestNum = convertedToMeters;
        }
    }

    cout << endl;

    sort(convertedMetersVec);

    cout << "[ ";
    for (double item : convertedMetersVec)
    {
        cout << item << ", ";
    }
    cout << " ]";

    cout << "\n\n";

    cout << "The sumInMeters: " << sumInMeters << "m == " << sumInMeters * cm_per_m << "cm" << endl;
    cout << "The smallest number: " << smallestNum << "m" << endl;
    cout << "The largest number: " << largestNum << "m" << endl;
}