#include <iostream>
#include <vector>
#include <string>

using namespace std;

int AddNumbers(int a, int b);               // Overloaded Functions
double AddNumbers(double a, double b);      // Overloaded Functions
int AddNumbers(int numbers[], size_t size); // Overloaded Functions

void PassByValue(int num);      // formal variable (copy)
void PassByReference(int& num); // refrence to actual variable (alias)

unsigned long long fibonacci(unsigned long long n);

int main()
{
    int num{10};         // actual variable
    int anotherNum{110}; // actaul variable

    cout << "num before calling PassByValue(): " << num << endl;
    PassByValue(num);
    cout << "num after calling PassByValue(): " << num << endl;

    cout << AddNumbers(4, 5) << endl;
    cout << AddNumbers(4.5, 5.1) << endl;

    int numbers[]{1, 2, 3, 4, 5};
    cout << AddNumbers(numbers, 5) << endl;

    cout << "num before calling PassByReference(): " << anotherNum << endl;
    PassByReference(anotherNum);
    cout << "num after calling PassByReference(): " << anotherNum << endl;

    cout << fibonacci(5);

    return 0;
}

int AddNumbers(int a, int b)
{
    return a + b;
}

double AddNumbers(double a, double b)
{
    return a + b;
}

int AddNumbers(int numbers[], size_t size)
{
    int total{0};

    for (size_t i = 0; i < size; ++i)
    {
        total += numbers[i];
    }

    return total;
}

void PassByValue(int num)
{
    num = 1000;
}

void PassByReference(int& num)
{
    num = 1000;
}

unsigned long long fibonacci(unsigned long long n)
{
    cout << n << endl;
    
    if (n <= 1)
    {
        return n;
    }
    return fibonacci(n-1) + fibonacci(n-2);
}
