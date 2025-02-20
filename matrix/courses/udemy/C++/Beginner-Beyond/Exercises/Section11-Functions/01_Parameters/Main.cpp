#include <iostream>
#include <vector>
#include <string>

using namespace std;

void PassByValue1(int num)
{
    num = 1000;
}

int main()
{
    int num{10};
    // int anotherNum{20};

    cout << "num before calling PassByValue1(): " << num << endl;
    PassByValue1(num);
    cout << "num after calling PassByValue1(): " << num << endl;



    return 0;
}