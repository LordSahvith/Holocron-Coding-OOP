#include "../../00_std_lib_facilities.h"

int main()
{
    vector<double> temps;

    for (double temp; cin >> temp;)
    {
        temps.push_back(temp);
    }

    double sum{0};
    double MAX_TEMP{1000};
    double MIN_TEMP{-1000};
    double high_temp{MIN_TEMP};
    double low_temp{MAX_TEMP};

    for (double temp : temps)
    {
        if (temp > high_temp)
        {
            high_temp = temp;
        }

        if (temp < low_temp)
        {
            low_temp = temp;
        }

        sum += temp;
    }

    cout << "High Temperature: " << high_temp << endl;
    cout << "Low Temperature: " << low_temp << endl;
    if (temps.size() > 0)
    {
        cout << "Average Temperature: " << sum / temps.size() << endl;
    }
}