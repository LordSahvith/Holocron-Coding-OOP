#include "../../00_std_lib_facilities.h"

struct Reading
{
    int hour;
    double temperature;
};

int main()
{
    ifstream tempsList{"temps.txt"};
    ofstream tempsOutList{"temps-out.txt"};

    if (!tempsList)
        return 0;

    if (!tempsOutList)
        return 0;

    vector<Reading> temps;
    int hour;
    double temperature;

    while (tempsList >> hour >> temperature)
    {
        if (hour < 0 || 23 < hour)
            break;
        temps.push_back(Reading{hour, temperature});
    }

    for (auto temp : temps)
    {
        // write to terminal
        cout << "hour: " << temp.hour << endl;
        cout << "temperature: " << temp.temperature << endl;

        // write to file
        tempsOutList << "hour: " << temp.hour << endl;
        tempsOutList << "temperature: " << temp.temperature << endl;
    }

    return 0;
}