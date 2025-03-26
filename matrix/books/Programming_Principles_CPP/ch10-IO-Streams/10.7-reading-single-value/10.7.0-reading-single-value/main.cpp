#include "../../../00_std_lib_facilities.h"

int main()
{
    cout << "Please enter an integer in the range 1 to 10 (inclusive):" << endl;
    int n{0};
    while (cin >> n && (1 <= n && n <= 10))
    {

        cout << "Sorry " << n << " is not in the [1:10] range; please try again" << endl;
    }
}