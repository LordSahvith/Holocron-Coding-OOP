#include <iostream>

using namespace std;

int sum_of_digits(int n);

void PlayAgain(bool& again);

int main()
{
    int n{0};

    bool testAgain{true};

    while (testAgain)
    {
        cout << "Enter Number: ";
        cin >> n;

        cout << "sum: " << sum_of_digits(n) << endl;

        PlayAgain(testAgain);
    }

    return 0;
}

int sum_of_digits(int n)
{
    if (n == 0)
    {
        return 0;
    }

    int lastDigit{n % 10};
    int result{lastDigit + sum_of_digits(n / 10)};
    return result;
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