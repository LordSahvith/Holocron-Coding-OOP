#include "../../../00_std_lib_facilities.h"

double my_abs(int x)
{
    if (x < 0)
    {
        return -x;
    }
    else if (x > 0)
    {
        return x;
    }
    // error: needs return value
}

int main()
{
}