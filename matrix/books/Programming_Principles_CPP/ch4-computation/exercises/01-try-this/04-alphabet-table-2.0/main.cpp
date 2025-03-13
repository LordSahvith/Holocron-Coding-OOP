#include "../../../../00_std_lib_facilities.h"

int main()
{
    for (int i = 0; i < 26; i++)
    {
        char ch{char('a' + i)};
        cout << ch << '\t' << int(ch) << endl;
    }
}