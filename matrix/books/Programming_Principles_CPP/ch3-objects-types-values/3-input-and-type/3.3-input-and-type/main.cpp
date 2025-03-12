// read name and age
#include "../../../00_std_lib_facilities.h"
#include <iomanip>

using namespace std;

int main()
{
    cout << "Please enter your full name and age\n";
    string first_name = "???"; // string variable
    string last_name = "???"; // string variable
    float age = 0.0f;             // integer variable
    cin >> first_name >> last_name >> age;  // read string and integer
    float months = age * 12.0f;
    float days = age * 365.25f;

    cout << "Hello, " << first_name << " " << last_name << endl;
    cout << "age: " << age << endl;
    cout << "age in months: " << months << endl;
    cout << "age in days: " << std::setprecision(10) << days << endl;
}
