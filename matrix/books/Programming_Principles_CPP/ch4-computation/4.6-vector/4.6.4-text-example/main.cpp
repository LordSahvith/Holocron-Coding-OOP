#include "../../../00_std_lib_facilities.h"

int main()
{
    vector<string> words;
    for (string word; cin >> word;)
    {
        words.push_back(word);
    }

    cout << "Number of words: " << words.size() << endl;

    sort(words);

    for (unsigned int i = 0; i < words.size(); i++)
    {
        if (i == 0 || words[i - 1] != words[i])
        {
            cout << words[i] << endl;
        }
    }
}