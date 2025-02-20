#include <iostream>
#include <iomanip>

using namespace std;

double a_penny_doubled_everyday(int days, double& amount);

void PlayAgain(bool& again);

int main()
{
    int days{0};

    bool testAgain{true};

    while (testAgain)
    {
        cout << "Enter Number of Days: ";
        cin >> days;

        double totalAmount{0.01};
        a_penny_doubled_everyday(days, totalAmount);
        cout << "\ntotal amount : $" << setprecision(10) << totalAmount << endl;

        PlayAgain(testAgain);
    }

    return 0;
}

double a_penny_doubled_everyday(int days, double& amount)
{
    cout << "\nDay " << days << ": $" << amount;

    if (days <= 1)
    {
        return 0;
    }

    return a_penny_doubled_everyday(days - 1, amount *= 2.0);
}

void PlayAgain(bool& again)
{
    char choice;
    cout << "Test Again? (y/n): ";
    cin >> choice;
    if (choice == 'n')
    {
        again = false;
    }
}