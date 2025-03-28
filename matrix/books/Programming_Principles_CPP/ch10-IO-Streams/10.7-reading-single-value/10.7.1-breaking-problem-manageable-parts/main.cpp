#include "../../../00_std_lib_facilities.h"

void skip_to_int();
int get_int();
int get_int(int low, int high);

int main()
{
    int n{get_int(1, 10)};
    cout << "n: " << n << endl;

    int m{get_int(2, 3000)};
    cout << "m: " << m << endl;
}

void skip_to_int()
{
    if (cin.fail())
    {
        cin.clear(); // set the state back to good();

        for (char ch; cin >> ch && !isdigit(ch);)
        {
            // nothing - throw away non-digits
        }

        if (!cin)
        {
            error("no input");
        }

        cin.unget();
    }
}

int get_int()
{
    int n{0};
    while (true)
    {
        if (cin >> n)
        {
            return n;
        }

        cout << "Sorry, that was not a number; please try again" << endl;
        skip_to_int();
    }
}

int get_int(int low, int high)
{
    cout << "Please enter an integer in the range " << low << " to " << high << " (inclusive):" << endl;

    while (true)
    {
        int n{get_int()};
        if (low <= n && n <= high)
        {
            return n;
        }

        cout << "Sorry, " << n << " is not in the [" << low << ':' << high << "] range; please try again" << endl;
    }
}