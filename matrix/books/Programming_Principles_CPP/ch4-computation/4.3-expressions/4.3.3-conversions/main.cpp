#include "../../../00_std_lib_facilities.h"

int main()
{
    double d = 2.5;
    int i = 2;

    double d2 = d / i; // 2.5
    int i2 = d / i;    // 1
    // int i3{d / i}; // error: double -> int conversion may narrow

    cout << "(double) 2.5 / 2 = " << d2 << endl;
    cout << "(int) 2.5 / 2 = " << i2 << endl;
}