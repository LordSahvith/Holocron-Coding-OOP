// read name and age
#include <iostream>

using namespace std;

int main()
{
    cout << "Please enter your name and age\n";
    string first_name = "???"; // string variable
    float age = 0;               // integer variable
    cin >> first_name >> age;         // read string and integer
    double months = age * 12;
    cout << "Hello, " << first_name << " (age " << age << " - " << months << " months)\n";
}
