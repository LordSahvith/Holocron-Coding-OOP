#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    cout << "Please enter a floating-point value: ";
    double n;
    cin >> n;
    cout << "n == " << n << endl;
    cout << "n+1 == " << n + 1 << endl;
    cout << "three times n == " << 3 * n << endl;
    cout << "twice n == " << n + n << endl;
    cout << "n squared == " << n * n << endl;
    cout << "half of n == " << n / 2 << endl;
    cout << "square root of n == " << sqrt(n) << endl;

    cout << "Please enter your first and second names:" << endl;
    string first;
    string second;
    cin >> first >> second;
    string name = first + " " + second;
    cout << "Hello, " << name << endl;

    cout << "Please enter two names:" << endl;
    string first2;
    string second2;
    cin >> first >> second;

    if (first == second)
    {
        cout << "Those are the same name.";
    }
    if (first < second)
    {
        cout << first << " is alphabetically before " << second << endl;
    }
    if (first > second)
    {
        cout << first << " is alphabetically after " << second << endl;
    }
}