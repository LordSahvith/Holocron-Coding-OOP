#include "../../00_std_lib_facilities.h"

const int not_a_reading = -7777; // less than absolute zero
const int not_a_month = -1;

struct Day
{
    vector<double> hour
    {
        vector<double>(24, not_a_reading)
    }
};

struct Month
{
    int month{not_a_month};
    vector<Day> day{32};
};

struct Year
{
    int year;
    vector<Month> month{12};
};
struct Reading
{
    int day;
    int hour;
    double temperature;
};

bool is_valid(const Reading& r)
{
    if (r.day < 1 || 31 < r.day)
        return false;
    if (r.hour < 0 || 23 < r.hour)
        return false;
    if (r.temperature < implausible_min || implausible_max < r.temperature)
        return false;
    return true;
}

void end_of_loop(istream& ist, char term, const string& message)
{
    if (ist.fail())
    {
        ist.clear();
        char ch;
        if (ist >> ch && ch == term) return;
        error(message);
    }
}

istream& operator>>(istream& is, Reading& r)
{
    char ch1;
    if (is >> ch1 && ch1 != '(')
    {
        is.unget();
        is.clear(ios_base::failbit);
        return is;
    }

    char ch2;
    int d;
    int h;
    double t;
    is >> d >> h >> t >> ch2;
    if (!is || ch2 != ')')
        error("bad reading");
    r.day = d;
    r.hour = h;
    r.temperature = t;
    return is;
}

istream& operator>>(istream& is, Month& m)
{
    char ch = 0;
    if (is >> ch && ch != '{')
    {
        is.unget();
        is.clear(ios_base::failbit);
        return is;
    }

    string month_maker;
    string mm;
    is >> month_maker >> mm;
    if (!is || month_maker != "month")
        error("bad start of month");
    m.month = month_to_int(mm);
    int duplicates = 0;
    int invalids = 0;
    for (Reading r; is >> r)
    {
        if (is_valid(r))
        {
            if (m.day[r.day].hour[r.hour] != not_a_reading)
            {
                ++duplicates;
            }
            m.day[r.day].hour[r.hour] = r.temperature;
        }
        else
        {
            ++invalids;
        }
    }

    if (invalids)
        error("invalid readings in month", invalids);
    if (duplicates)
        error("duplicate reading in month", duplicates);
    end_of_loop(is, '{', "bad end of month");
    return is;
}

constexpr int implausible_min = -200;
constexpr int implausible_max = 200;

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