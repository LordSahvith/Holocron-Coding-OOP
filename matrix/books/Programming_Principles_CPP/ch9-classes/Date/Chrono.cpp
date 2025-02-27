#include "Chrono.h"

namespace Chrono
{
Date::Date(int yy, Month mm, int dd) : year{yy}, month{mm}, day{dd}
{
    if (!is_date(yy, mm, dd))
        throw Invalid{};
}

const Date& default_date()
{
    static Date dd{2001, Month::jan, 1};
    return dd;
}

Date::Date() : year{default_date().get_year()}, month{default_date().get_month()}, day{default_date().get_day()}
{
}

void Date::add_day(int n)
{
    day += n;
}

void Date::add_month(int n)
{
    // ...
}

void Date::add_year(int n)
{
    if (month == Month::feb && day == 29 && !leapyear(year + n))
    {
        month = Month::mar;
        day = 1;
    }
    year += n;
}

bool is_date(int year, Month month, int day)
{
    // assume that year is valid

    if (day <= 0)
        return false; // day must be positve
    if (month < Month::jan || Month::dec < month)
        return false;

    int days_in_month = 31;

    switch (month)
    {
    case Month::feb:
        days_in_month = (leapyear(year)) ? 29 : 28;
        break;
    case Month::apr:
    case Month::jun:
    case Month::sep:
    case Month::nov:
        days_in_month = 30;
        break;
    default:
        break;
    }

    if (days_in_month < day)
        return false;

    return true;
}

bool leapyear(int year)
{
    return year % 4 == 0;
}

bool operator==(const Date& a, const Date& b)
{
    return a.get_year() == b.get_year() && a.get_month() == b.get_month() && a.get_day() == b.get_day();
}

bool operator!=(const Date& a, const Date& b)
{
    return !(a == b);
}

ostream& operator<<(ostream& os, const Date& dd)
{
    return os << '(' << dd.get_year() << ',' << int(dd.get_month()) << ',' << dd.get_day() << ')';
}

istream& operator>>(istream& is, Date& dd)
{
    int year, month, day;
    ;
    char ch1, ch2, ch3, ch4;
    is >> ch1 >> year >> ch2 >> month >> ch3 >> day >> ch4;
    if (!is)
        return is;
    if (ch1 != '(' || ch2 != ',' || ch3 != ',' || ch4 != ')')
    {
        is.clear();
        return is;
    }

    dd = Date(year, Month(month), day);

    return is;
}

Day day_of_week(const Date& date)
{
    Day dayOfWeek;

    switch ((date.get_day() % 7) + 1)
    {
    case 1:
        dayOfWeek = Day::sunday;
        break;
    case 2:
        dayOfWeek = Day::monday;
        break;
    case 3:
        dayOfWeek = Day::tuesday;
        break;
    case 4:
        dayOfWeek = Day::wednesday;
        break;
    case 5:
        dayOfWeek = Day::thursday;
        break;
    case 6:
        dayOfWeek = Day::thursday;
        break;
    case 7:
        dayOfWeek = Day::thursday;
        break;    
    default:
        break;
    }

    return dayOfWeek;
}

Date next_Sunday(const Date& date)
{    
    return Date(date);
}

Date next_weekday(const Date& date)
{
    return Date(date);
}
} // namespace Chrono