#include "../../00_std_lib_facilities.h"

// Structs are better suited for "Plain Data" or simple classes

struct Date
{
    int year;
    int month;
    int day;
};

// helper function for Date
void PrintDate(Date& DateRef)
{
    cout << DateRef.month << "/" << DateRef.day << "/" << DateRef.year;
}

int main()
{
    Date Today;
    Today.day = 26;
    Today.month = 2;
    Today.year = 2025;

    PrintDate(Today);

    return 0;
}