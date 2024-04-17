#include <iostream>

using namespace std;

int main()
{
    double x; // declared, but not defined - value is undefined
    double y = x; // value is undefined
    double z = 2.0 + x; // the meaning of + and the value of z are undefined

    return 0;
}