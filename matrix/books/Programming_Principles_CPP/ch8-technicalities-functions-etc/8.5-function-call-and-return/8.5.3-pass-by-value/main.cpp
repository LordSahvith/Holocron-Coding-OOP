#include "../../../00_std_lib_facilities.h"

int f(int x)
{
    x = x + 1;
    return x;
}

int main()
{
    int xx{0};
    cout << f(xx) << endl; // 1
    cout << xx << endl;    // 0

    int yy{7};
    cout << f(yy) << endl; // 8
    cout << yy << endl;    // 7
}