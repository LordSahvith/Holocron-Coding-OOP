#include "../../../00_std_lib_facilities.h"

int main()
{
    vector<double> cityDistances{};
    double sum{0.0};
    double smallestDistance{0.0};
    double largestDistance{0.0};

    cout << "Enter a at leaset 3 doubles: ";

    double distance{0.0};
    while (cin >> distance)
    {

        cityDistances.push_back(distance);
        sum += distance;
    }

    bool isFirstLoop{true};
    for (size_t i = 0; i < cityDistances.size(); i++)
    {
        double difference{0.0};

        if (i == cityDistances.size() - 1)
        {
            break;
        }

        if (cityDistances[i] > cityDistances[i + 1])
        {
            difference = cityDistances[i] - cityDistances[i + 1];
        }
        else
        {
            difference = cityDistances[i + 1] - cityDistances[i];
        }

        if (isFirstLoop)
        {
            smallestDistance = difference;
            largestDistance = difference;
            isFirstLoop = false;
        }

        if (difference < smallestDistance)
        {
            smallestDistance = difference;
        }

        if (difference > largestDistance)
        {
            largestDistance = difference;
        }
    }

    cout << "sum: " << sum << endl;
    cout << "smallest: " << smallestDistance << endl;
    cout << "largest: " << largestDistance << endl;
    cout << "mean: " << cityDistances[0] + cityDistances[1] / 2 << endl;
}