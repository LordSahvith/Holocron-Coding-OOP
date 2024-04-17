#include <iostream>

using namespace std;

int main()
{
    char c = 'x'; // value 'x'
    int i1 = c; // value 120 (x ASCII value)
    int i2 = 'x'; // value 120 (x ASCII value)
    char c2 = i1; // value 'x' converted from int to char

    cout << c << ' ' << i1 << ' ' << i2 << ' ' << c2 << '\n';

    double d1 = 2.3;
    double d2 = d1 + 2; // 2 is converted to 2.0 before adding
    if (d1 < 0) // 0 is converted to 0.0 before comparison
        cout << "d1 is negative";

    return 0;
}