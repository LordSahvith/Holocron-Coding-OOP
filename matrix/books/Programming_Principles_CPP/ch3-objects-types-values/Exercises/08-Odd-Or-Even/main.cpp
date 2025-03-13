#include "../../../../00_std_lib_facilities.h"

int main()
{
    int num{0};
    cout << "Enter an integer: ";
    cin >> num;

    string oddEven{num % 2 == 0 ? "even" : "odd"};
    cout << "the value " << num << " is an " << oddEven << " number" << endl;
}