#include "../../00_std_lib_facilities.h"

namespace Chrono
{
enum class Month
{
    jan = 1,
    feb,
    mar,
    apr,
    may,
    jun,
    jul,
    aug,
    sep,
    oct,
    nov,
    dec
};

enum class Day
{
    sunday,
    monday,
    tuesday,
    wednesday,
    thursday,
    friday,
    saturday
};

class Date
{
  public:
    class Invalid
    {
    }; // to throw as an exception

    Date(int y, Month m, int d); // check for valid date and initialize
    Date();                      // default constructor
    // the default copy operations are fine

    // nonmodifying operations:
    int get_day() const
    {
        return day;
    }

    Month get_month() const
    {
        return month;
    }

    int get_year() const
    {
        return year;
    }

    // modifying operations:
    void add_day(int n);
    void add_month(int n);
    void add_year(int n);

  private:
    int year;
    Month month;
    int day;
};

bool is_date(int y, Month m, int d); // true for valid date
bool leapyear(int y);                // true if y is a leap year

bool operator==(const Date& a, const Date& b);
bool operator!=(const Date& a, const Date& b);

ostream& operator<<(ostream& os, const Date& d);
istream& operator>>(istream& is, Date& dd);

Day day_of_week(const Date& d);   // day of week of d
Date next_Sunday(const Date& d);   // next Sunday after d
Date next_weekday(const Date& d); // next weekday after d
} // namespace Chrono