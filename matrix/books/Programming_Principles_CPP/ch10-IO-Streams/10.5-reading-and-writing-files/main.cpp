#include "../../00_std_lib_facilities.h"

struct Reading
{
    int hour;
    double temperature;
};

int main()
{
    string inName{"in-file.txt"};
    ifstream inStream{inName};
    if (!inStream)
    {
        error("can't open input file ", inName);
    }

    string outName{"out-file.txt"};
    ofstream outStream{outName};
    if (!outStream)
    {
        error("can't open output file ", outName);
    }

    vector<Reading> temps;
    int hour;
    double temperature;
    while (inStream >> hour >> temperature)
    {
        if (hour < 0 || 23 < hour)
        {
            error("hour out of range");
        }
        temps.push_back(Reading{hour, temperature});
    }

    for (Reading temp : temps)
    {
        outStream << '(' << temp.hour << ',' << temp.temperature << ')' << endl;
    }
}