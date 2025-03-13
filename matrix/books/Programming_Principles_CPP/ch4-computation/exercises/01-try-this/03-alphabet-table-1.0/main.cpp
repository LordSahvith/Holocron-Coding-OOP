#include "../../../../00_std_lib_facilities.h"

int main()
{
    int count{0};
    while (count < 26)
    {
        char ch{char('a' + count)};
        cout << ch << '\t' << int(ch) << endl;
        count++;
    }
}