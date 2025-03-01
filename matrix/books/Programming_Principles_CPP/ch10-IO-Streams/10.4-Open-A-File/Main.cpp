#include "../../00_std_lib_facilities.h"

struct Reading
{
    int hour;
    double temperature;
};

int main()
{
    ifstream tempsList{"temps.txt"};
    if (!tempsList)
        return 0;

    ofstream tempsOutList{"temps-out.txt"};
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
        cout << setw(15) << left << "hour: " << temp.hour << endl;
        cout << setw(15) << left << "temperature: " << temp.temperature << endl;

        // write to file
        tempsOutList << setw(15) << left << "hour: " << temp.hour << endl;
        tempsOutList << setw(15) << left << "temperature: " << temp.temperature << endl;
    }

    return 0;
}