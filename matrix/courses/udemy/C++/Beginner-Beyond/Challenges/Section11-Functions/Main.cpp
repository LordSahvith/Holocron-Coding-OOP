// Section 11
// Challenge
/*
    This challenge is about using a collection (list) of integers and allowing the user
    to select options from a menu to perform operations on the list.

    Your program should display a menu options to the user as follows:

    P - Print numbers
    A - Add a number
    M - Display mean of the numbers
    S - Display the smallest number
    L - Display the largest number
    Q - Quit

    Enter your choice:

    The program should only accept valid choices from the user, both upper and lowercase selections should be allowed.
    If an illegal choice is made, you should display, "Unknown selection, please try again" and the menu options should
    be displayed again.


    If the user enters 'P' or 'p', you should display all of the elements (ints) in the list.
    If the list is empty you should display "[] - the list is empty"
    If the list is not empty then all the list element should be displayed inside square brackets separated by a space.
    For example, [ 1 2 3 4 5 ]

    If the user enters 'A' or 'a' then you should prompt the user for an integer to add to the list
    which you will add to the list and then display it was added. For example, if the user enters 5
    You should display, "5 added".
    Duplicate list entries are OK

    If the user enters 'M' or 'm'  you should calculate the mean or average of the elements in the list and display it.
    If the list is empty you should display, "Unable to calculate the mean - no data"

    If the user enters 'S' or 's' you should display the smallest element in the list.
    For example, if the list contains [2 4 5 1],  you should display, "The smallest number is 1"
    If the list is empty you should display, "Unable to determine the smallest number - list is empty"

    If the user enters 'L' or 'l' you should display the largest element in the list
    For example, if the list contains [2 4 5 1], you should display, "The largest number is 5"
    If the list is empty you should display, "Unable to determine the largest number - list is empty"

    If the user enters 'Q' or 'q' then you should display 'Goodbye" and the program should terminate.

    Before you begin. Write out the steps you need to take and decide in what order they should be done.
    Think about what loops you should use as well as what you will use for your selection logic.

    This exercise can be challenging! It may likely take a few attempts before you complete it -- that's OK!

    Finally, be sure to test your program as you go and at the end.

    Hint: Use a vector!

    Additional functionality if you wish to extend this program.

    - search for a number in the list and if found display the number of times it occurs in the list
    - clearing out the list (make it empty again) (Hint: the vector class has a .clear() method)
    - don't allow duplicate entries
    - come up with your own ideas!

    Good luck!

*/
#include <iostream>
#include <vector>

using namespace std;

void PrintMenu();
char GetSelection();
void Quit();
void PrintNumbers(const vector<int>& numberList);
void AddNumber(vector<int>& numberList);
void DisplayMean(const vector<int>& numberList);
void DisplaySmallestNumber(const vector<int>& numberList);
void DisplayLargestNumber(const vector<int>& numberList);

int main()
{
    vector<int> List{};
    char Selection{};

    do
    {
        PrintMenu();
        Selection = GetSelection();
        switch (Selection)
        {
        case 'Q':
            Quit();
            break;
        case 'P':
            PrintNumbers(List);
            break;
        case 'A':
            AddNumber(List);
            break;
        case 'M':
            DisplayMean(List);
            break;
        case 'S':
            DisplaySmallestNumber(List);
            break;
        case 'L':
            DisplayLargestNumber(List);
            break;
        default:
            cout << "Unknown selection, please try again" << endl;
            break;
        }
    } while (Selection != 'Q');

    return 0;
}

void PrintMenu()
{
    cout << "\n*===================================*" << endl;
    cout << "\nP - Print numbers" << endl;
    cout << "A - Add a number" << endl;
    cout << "M - Display mean of the numbers" << endl;
    cout << "S - Display the smallest number" << endl;
    cout << "L - Display the largest number" << endl;
    cout << "Q - Quit" << endl;
    cout << "\n*===================================*" << endl;
    cout << "\nEnter your choice: ";
}

char GetSelection()
{
    char Choice{};
    cin >> Choice;
    return toupper(Choice);
}

void Quit()
{
    cout << "Goodbye.";
}

void PrintNumbers(const vector<int>& numberList)
{
    if (numberList.size() > 0)
    {
        cout << "[";
        for (size_t Index{0}; Index < numberList.size(); Index++)
        {
            size_t ListItem = numberList.at(Index);

            if (numberList.size() > 1 && Index < numberList.size() - 1)
            {
                cout << ListItem << ", ";
            }
            else
            {
                cout << ListItem;
            }
        }
        cout << "]";
    }
    else
    {
        cout << "[] - the list is empty." << endl;
    }
}

void AddNumber(vector<int>& numberList)
{
    int Number{};
    cout << "Enter an integer to add to the list: ";
    cin >> Number;
    numberList.push_back(Number);
    cout << Number << " added" << endl;
}

void DisplayMean(const vector<int>& numberList)
{
    if (!numberList.empty())
    {
        int Result{0};

        for (int Item : numberList)
        {
            Result += Item;
        }
        cout << "The Mean is: " << static_cast<double>(Result) / numberList.size() << endl;
    }
    else
    {
        cout << "List is empty." << endl;
    }
}

void DisplaySmallestNumber(const vector<int>& numberList)
{
    if (!numberList.empty())
    {
        int SmallestNumber = numberList.at(0);

        for (auto ListNumber : numberList)
        {
            if (ListNumber < SmallestNumber)
            {
                SmallestNumber = ListNumber;
            }
        }
        cout << "Smallest Number is: " << SmallestNumber << endl;
    }
    else
    {
        cout << "List is empty." << endl;
    }
}

void DisplayLargestNumber(const vector<int>& numberList)
{
    if (!numberList.empty())
    {
        int LargestNumber = numberList.at(0);

        for (auto ListNumber : numberList)
        {
            if (ListNumber > LargestNumber)
            {
                LargestNumber = ListNumber;
            }
        }
        cout << "Largest Number is: " << LargestNumber << endl;
    }
    else
    {
        cout << "List is empty." << endl;
    }
}