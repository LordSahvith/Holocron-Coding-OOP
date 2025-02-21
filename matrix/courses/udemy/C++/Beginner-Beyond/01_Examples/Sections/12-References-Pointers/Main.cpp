#include <iostream>
#include <vector>
#include <string>

using namespace std;

void AccessAndDereferncePoniter();
void DynamicMemory();
void ArraysAndPointers();

int main()
{
    AccessAndDereferncePoniter();
    DynamicMemory();
    ArraysAndPointers();

    return 0;
}

void AccessAndDereferncePoniter()
{
    cout << "*------------ Access & Dereference -------------*" << endl;
    int num{10};
    int* pointer1{&num}; // get address (&) of num and store in pointer1

    cout << "num: " << num << endl;           // value
    cout << "pointer1: " << pointer1 << endl; // address

    cout << "&num: " << &num << endl;           // address
    cout << "*pointer1: " << *pointer1 << endl; // value (dereference to get value)

    num += 5;
    cout << "num += 5" << endl;
    cout << "num: " << num << endl;             // value
    cout << "*pointer1: " << *pointer1 << endl; // value

    vector<string> name{"lord", "savith"};
    vector<string>* pointer2{&name};

    cout << "name: " << (*pointer2).at(1) << endl; // dereference and call that's object's method
    cout << "name: " << pointer2->at(1) << endl;   // equivalent as above

    cout << "full name: ";
    for (auto n : *pointer2) // dereference to get object
    {
        cout << n << " ";
    }

    cout << "\n*--------------------------------------*\n" << endl;
}

void DynamicMemory()
{
    cout << "*------------ Dynamic Memory -------------*" << endl;
    int* int_ptr{nullptr};

    int_ptr = new int; // stored on Heap (Free Strore)

    cout << "Heap Address: " << int_ptr << endl;

    delete int_ptr; // frees up storage

    cout << "*---------------------------------------*\n" << endl;
}

void ArraysAndPointers()
{
    cout << "*------------ Arrays & Pointers -------------*" << endl;

    int scores[]{100, 150, 225};
    int* scores_ptr{scores}; // array name points to first index so it gives the address so no & needed

    cout << "scores: " << scores << endl;
    cout << "scores_ptr: " << scores_ptr << endl;

    cout << "\nScores:" << endl;
    cout << *scores << endl;
    cout << *(scores + 1) << endl;
    cout << *(scores + 2) << endl;
    cout << scores[0] << endl;
    cout << scores[1] << endl;
    cout << scores[2] << endl;

    cout << "\nScores Pointer:" << endl;
    cout << *scores_ptr << endl;
    cout << *(scores_ptr + 1) << endl;
    cout << *(scores_ptr + 2) << endl;
    cout << scores_ptr[0] << endl;
    cout << scores_ptr[1] << endl;
    cout << scores_ptr[2] << endl;

    cout << "*---------------------------------------*\n" << endl;
}
