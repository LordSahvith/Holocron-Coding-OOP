#include <iostream>

using std::cin;
using std::cout;
using std::string;

int main()
{
    string previous = "";
    string current;

    while (cin >> current)
    {
        if (previous == current)
        {
            cout << "repeated word: " << current << "\n";
        }
        previous = current;
    }

    return 0;
}