#include <iostream>

using namespace std;

int main() {
    int a = 3;  // a starts out with the value 3 - intialization
    cout << "a:" << a;
    a = 4;      // a gets the value 4 ("becomes 4") - assignment
    cout << "a:" << a;
    int b = a;  // b starts out with a copy of a's value (this is, 4) - intialization
    cout << "a:" << a << " b:" << b;
    b = a + 5;  // b gets the value a + 5 (that is, 9) - assignment
    cout << "a:" << a << " b:" << b;
    a = a + 7;  // a gets the value a + 7 (that is, 11) - assignment
    cout << "a:" << a << " b:" << b;

    string x = "alpha"; // x starts out with the value "alpha" - intialization
    cout << "x:" << x;
    x = "beta";         // x gets the value "beta" (becomes "beta") - assignment
    cout << "x:" << x;
    string y = x;      // y starts out with a copy of a's value (that is, "beta") - inialization
    cout << "x:" << x;
    y = x + "gamma";   // y gets the value x + "gamma" (that is, betagamma) - assingment
    cout << "x:" << x << " y:" << y;
    x = x + "delta";    // x gets the value x + "delta" (that is, "betadelta"); - assingment
    cout << "x:" << x << " y:" << y;

    return 0;
}