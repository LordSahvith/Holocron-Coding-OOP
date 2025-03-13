#include "../../../../00_std_lib_facilities.h"

int square(int x)
{
    int result{0};
    for (int i = 0; i < x; i++)
    {
        result += x;
    }
    return result;
}

int main()
{
    cout << "square(4): " << square(4) << endl; // 4 + 4 + 4 + 4 = 16
    cout << "square(5): " << square(5) << endl; // 5 + 5 + 5 + 5 + 5 = 25
}