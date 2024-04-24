#include <iostream>

using namespace std;

int main ()
{
    int length {20}; // a literal integer (used to intialize a variable) is a expression
    int width {40}; // 40 is also an expression
    int area = length * width; // a multiplication, also an expression

    int perimeter = (length + width) * 2;

    cout << "area: " << area << endl;
    cout << "perimeter: " << perimeter << endl;

    return 0;
}