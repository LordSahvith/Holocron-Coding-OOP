#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    cout << "Please enter a floating-point value: ";
    double n;
    cin >> n;
    cout << "n == " << n
         << "\nn+1 == " << n + 1
         << "\nthree times n == " << 3 * n
         << "\ntwice n == " << n + n
         << "\nn squared == " << n * n
         << "\nhalf of n == " << n / 2
         << "\nsquare root of n == " << sqrt(n)
         << "\n";

    cout << "Please enter your first and second names:\n";
    string first;
    string second;
    cin >> first >> second;
    string name = first + " " + second;
    cout << "Hello, " << name << "\n";

    cout << "Please enter two names:\n";
    string first2;
    string second2;
    cin >> first >> second;
    
    if (first == second) cout << "Those are the same name.";
    if (first < second) cout << first << " is alphabetically before " << second << "\n";
    if (first > second) cout << first << " is alphabetically after " << second << "\n";

    return 0;
}