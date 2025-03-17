#include "../../../00_std_lib_facilities.h"

int main()
{
    try
    {
        vector<int> v;
        for (int x; cin >> x;)
        {
            v.push_back(x);
        }
        for (size_t i = 0; i <= v.size(); i++)
        {
            cout << "v[" << i << "] == " << v[i] << endl;
        }
    }
    catch (out_of_range)
    {
        cerr << "Oops! Range Error" << endl;
        return 1;
    }
    catch (const exception& e)
    {
        cerr << "Exception: something went wrong" << endl;
        return 2;
    }
}