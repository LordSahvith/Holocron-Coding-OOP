#include "../../../00_std_lib_facilities.h"

int main()
{
    vector<int> vec{};
    cout << vec.size() << endl;

    vec.push_back(4);
    vec.push_back(16);

    cout << vec.size() << endl;

    for (int num : vec)
    {
        cout << num << ", ";
    }
}