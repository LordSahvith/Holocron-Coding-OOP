// read name and age
#include <iostream>

using namespace std;

int main()
{
    cout << "Please enter your name and age\n";
    string first_name; // string variable
    int age;           // integer variable
    cin >> first_name; // read string
    cin >> age;        // read an integer
    cout << "Hello, " << first_name << " (age " << age << ")\n";
}
