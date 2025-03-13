#include "../../../00_std_lib_facilities.h"

int main()
{
    vector<double> temps;
    for (double temp; cin >> temp;) // terminate with anything other than a double/integer
    {
        temps.push_back(temp);
    }

    for (double temp : temps)
    {
        cout << temp << endl;
    }

    // compute mean temperature
    double sum{0};
    for (double temp : temps)
    {
        sum += temp;
    }
    cout << "Average temperature: " << sum / temps.size() << endl;

    // compute median temperature
    sort(temps);
    cout << "Median temperature: " << temps[temps.size() / 2] << endl;
}