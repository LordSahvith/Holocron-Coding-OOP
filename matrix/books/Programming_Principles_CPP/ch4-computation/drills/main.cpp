#include "../../00_std_lib_facilities.h"

int main()
{
    double currentNum{0};
    double smallestNum{0};
    double largestNum{0};

    while (cin >> currentNum)
    {
        cout << currentNum;

        if (currentNum < smallestNum)
        {
            smallestNum = currentNum;
            cout << " is the smallest so far" << endl;
        }

        if (currentNum > largestNum)
        {
            largestNum = currentNum;
            cout << " is the largest so far" << endl;
        }
    }
}