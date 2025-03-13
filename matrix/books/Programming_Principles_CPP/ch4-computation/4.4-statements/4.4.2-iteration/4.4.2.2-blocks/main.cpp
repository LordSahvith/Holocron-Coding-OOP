#include "../../../../00_std_lib_facilities.h"

int main()
{
    int i{0};
    while (i < 100)
    { // start of block
        cout << i << '\t' << (i * i) << endl;
        ++i;
    } // end of block

    if (true)
    { // start of block
        cout << "Blocks are chunks of code" << endl;
    } // end of block
}