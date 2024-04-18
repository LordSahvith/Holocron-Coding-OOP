#include <iostream>

using namespace std;

int main()
{
    int roomWidth {0};
    int roomLength {0};

    cout << "Enter the width of the room: ";
    cin >> roomWidth;

    cout << "Enter the length of the room: ";
    cin >> roomLength;

    cout << "The area of the room is " << roomWidth * roomLength << " sq ft" << endl;
    
    return 0;
}