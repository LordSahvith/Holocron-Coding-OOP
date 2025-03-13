#include "../../../00_std_lib_facilities.h"

int main()
{
    vector<int> v{1, 2, 3, 4, 5, 6};
    cout << v[4] << endl; // 5

    vector<string> philosopher{"Kant", "Plato", "Hume", "Kiekegaard"};
    cout << philosopher[1] << endl; // Plato
}