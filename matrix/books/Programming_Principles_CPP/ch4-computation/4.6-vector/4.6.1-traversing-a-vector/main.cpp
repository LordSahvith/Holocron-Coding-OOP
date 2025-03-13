#include "../../../00_std_lib_facilities.h"

int main()
{
    vector<int> v{1, 2, 3, 4, 5, 6};
    for (unsigned int i = 0; i < v.size(); i++)
    {
        cout << v[i] << ", ";
    }

    cout << endl;

    vector<string> philosophers{"Kant", "Plato", "Hume", "Kiekegaard"};
    for (string philosopher : philosophers)
    {
        cout << philosopher << ", "; // Plato
    }
}