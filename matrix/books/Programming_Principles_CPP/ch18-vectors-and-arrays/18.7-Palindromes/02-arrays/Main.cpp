#include "../../../00_std_lib_facilities.h"

bool is_palindrome(const char s[], int n)
{
    int first = 0;       // index of first letter
    int last = n - 1;    // index of last letter
    while (first < last) // we haven't reached middle
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

istream& read_word(istream& is, char* buffer, int max)
{
    is.width(max);
    is >> buffer;

    return is;
}

int main()
{
    constexpr int max = 128;
    for (char s[max]; read_word(cin, s, max);) {
        cout << s << " is";
        if (!is_palindrome(s, strlen(s))) {
            cout << " not";
        }
        cout << " a palindrome.\n";
    }

    return 0;
}