#include "../../../00_std_lib_facilities.h"

void init(vector<double>& v)
{
    for (size_t i = 0; i < v.size(); i++)
    {
        v[i] = i;
    }
}

void print(const vector<double>& v)
{
    cout << "{ ";
    for (size_t i = 0; i < v.size(); i++)
    {
        cout << v[i];
        if (i != v.size() - 1)
        {
            cout << ", ";
        }
    }
    cout << " }" << endl;
}

int f(int& x)
{
    x = x + 1;
    return x;
}

int main()
{
    vector<double> vd1(10);
    vector<double> vd2(1000);

    init(vd1);
    init(vd2);

    print(vd1);
    print(vd2);

    int xx{0};
    cout << f(xx) << endl;
    cout << xx << endl;

    int yy{7};
    cout << f(yy) << endl;
    cout << yy << endl;
}