#include "../../../../00_std_lib_facilities.h"

int main() {
    int num1{0};
    int num2{0};

    cout << "Enter 2 integers: ";
    cin >> num1 >> num2;

    cout << endl;

    // smaller
    int smallerNum{num1 < num2 ? num1 : num2};
    cout << "smaller number: " << smallerNum << endl;

    // larger
    int largerNum{num1 > num2 ? num1 : num2};
    cout << "larger number: " << largerNum << endl;

    // sum
    cout << "Sum: " << num1 + num2 << endl;

    // difference
    cout << "difference: " << largerNum - smallerNum << endl;

    // product
    cout << "product: " << num1 * num2 << endl;
}