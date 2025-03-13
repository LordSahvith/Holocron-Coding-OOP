#include "../../00_std_lib_facilities.h"

int square(int x);

int main()
{
    cout << square(4) << endl;
    cout << square(44) << endl;
}

int square(int x)
{
    return x * x;
}