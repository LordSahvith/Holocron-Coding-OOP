#include "../../../00_std_lib_facilities.h"

constexpr double pi = 3.14159;

double use(double num)
{
    constexpr double c1{pi + 7};
    const double c2{num + c1}; // const can use a run-time var (num)
    return c2;
}

int main()
{
    // pi = 7; // error: assignment of read-only variable 'pi'
    double radius{2.0};
    double circumference = 2 * pi * radius;

    cout << use(circumference) << endl;                                                                                         
}