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

    // compute median temperature
    sort(temps);
    cout << "Median temperature: " << temps[temps.size() / 2] << endl;
}