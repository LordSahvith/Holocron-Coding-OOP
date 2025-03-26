#include "../../00_std_lib_facilities.h"

void fill_vector(istream& instream, vector<int>& vec, char terminator);

int main()
{
    string inName{"in-file.txt"};
    ifstream inStream{inName};
    if (!inStream)
    {
        error("can't open input file ", inName);
    }

    string outName{"out-file.txt"};
    ofstream outStream{outName};
    if (!outStream)
    {
        error("can't open output file ", outName);
    }

    vector<int> nums;

    fill_vector(inStream, nums, '*');

    for (int num : nums)
    {
        outStream << num << " ";
    }
}

void fill_vector(istream& instream, vector<int>& vec, char terminator)
{
    for (int i; instream >> i;)
    {
        vec.push_back(i);
    }

    if (instream.eof())
    {
        return;
    }

    if (instream.fail()) // clean up the mess as best we can and report th problem
    {
        instream.clear(); // clear stream state

        char c;
        instream >> c;
        if (c != terminator) // unexpected character
        {
            instream.unget();                  // put that character back
            instream.clear(ios_base::failbit); // set state to fail()
        }
    }
}
