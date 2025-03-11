#include "../../../00_std_lib_facilities.h"

bool is_palindrome(const string& s)
{
    int first = 0;             // index of first letter
    int last = s.length() - 1; // index of last letter
    while (first < last)       // we haven't reached middle
    {
        if (s[first] != s[last])
        {
            return false;
        }
        ++first; // move forward
        --last;  // move backward
    }
    return true;
}

int main()
{
    for (string s; cin >> s;)
    {
        cout << s << " is";
        if (!is_palindrome(s))
        {
            cout << " not";
        }
        cout << " a palindrome\n";
    }

    return 0;
}