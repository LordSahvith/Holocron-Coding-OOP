#include "../../00_std_lib_facilities.h"

int main()
{
    ifstream script{"../TextFile.txt"};

    if (!script)
    {
        cerr << "Problem opening file." << endl;
        return 0;
    }

    cout << "File Opened." << endl;

    ofstream outScript{"../NewTextFile.txt"};

    if (!outScript)
    {
        cerr << "Problem opening file." << endl;
        return 0;
    }

    cout << "File Opened." << endl;

    string word;
    vector<string> words;

    while (script >> word)
    {
        words.push_back(word);
    }

    script.close();
    cout << "File Closed." << endl;

    for (string word : words)
    {
        outScript << word;
    }

    outScript.close();
    cout << "File Closed." << endl;

    return 0;
}