#include "../../../00_std_lib_facilities.h"

int main()
{
    int miles{0};
    bool again{true};

    while (again)
    {
        cout << "\nEnter miles: ";
        cin >> miles;
        cout << "KM: " << miles / 1.609 << endl;

        char choice;
        cout << "\nAnother? (Y/N): ";
        cin >> choice;

        if (toupper(choice) == 'N')
        {
            again = false;
        }
    }

    return 0;
}