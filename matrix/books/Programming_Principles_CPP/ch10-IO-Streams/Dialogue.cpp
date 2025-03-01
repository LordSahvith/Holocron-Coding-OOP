#include "../../00_std_lib_facilities.h"

struct Dialogue
{
    string Character;
    string Script;
};

bool validateFile(ifstream& file);
bool validateFile(ofstream& file);
bool copyFileContents(string fileName, vector<string>& contents);
bool writeContentsToFile(vector<string>& contents);

int main()
{
    vector<string> contents;

    if (!copyFileContents("../TextFile.txt", contents))
        return 0;

    for (string word : contents)
    {
        cout << word;
    }

    return 0;
}

bool validateFile(ifstream& file)
{
    if (!file)
    {
        cerr << "Problem opening file." << endl;
        return false;
    }

    return true;
}

bool validateFile(ofstream& file)
{
    if (!file)
    {
        cerr << "Problem opening file." << endl;
        return false;
    }

    return true;
}

bool copyFileContents(string fileName, vector<string>& contents)
{
    ifstream scriptFile{fileName};
    if (!validateFile(scriptFile))
    {
        cerr << "Problem opening file." << endl;
        return false;
    }

    string word;
    while (scriptFile >> word)
    {
        contents.push_back(word);
    }

    return true;
}

bool writeContentsToFile(vector<string>& contents)
{
    ofstream outScript{"../NewTextFile.txt"};

    if (!validateFile(outScript))
    {
        cerr << "Problem opening file." << endl;
        return false;
    }

    for (string word : contents)
    {
        outScript << word;
    }

    return true;
}
