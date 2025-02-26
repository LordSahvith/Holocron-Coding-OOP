#include "../../../../00_std_lib_facilities.h"

int main()
{
    vector<string> dislikedWords{"office", "politics"};

    vector<string> typedWords;

    string current;

    cout << "Enter phrase: ";

    while (cin >> current)
    {
        if (current == ";")
        {
            break;
        }

        typedWords.push_back(current);
    }

    for (unsigned i{0}; i < typedWords.size(); ++i)
    {
        for (unsigned j{0}; j < dislikedWords.size(); ++j)
        {
            if (typedWords.at(i) == dislikedWords.at(j))
            {
                typedWords.at(i) = "bleep";
            }
        }

        cout << typedWords.at(i) << " ";
    }

    return 0;
}