#include "../../00_std_lib_facilities.h"

int main()
{
    try
    {
        vector<int> v(10);
        v[5] = 7;
        if (v[5] != 7)
        {
            cout << "Success!" << endl;
        }
        else
        {
            cout << "Fail!" << endl;
        }

        return 0;
    }
    catch (exception& e)
    {
        std::cerr << e.what() << endl;
        return 1;
    }
}