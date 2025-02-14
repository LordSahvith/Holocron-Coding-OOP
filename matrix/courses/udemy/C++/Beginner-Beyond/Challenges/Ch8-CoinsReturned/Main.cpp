#include <iostream>

using namespace std;

int main()
{
    const int FIVE_DOLLAR_VALUE {500};
    const int DOLLAR_VALUE {100};
    const int QUARTER_VALUE {25};
    const int DIME_VALUE {10};
    const int NICKLE_VALUE {5};
    const int PENNY_VALUE {1};

    int FiveDollars {0};
    int Dollars {0};
    int Quarters {0};
    int Dimes {0};
    int Nickels {0};
    int Pennies {0};

    int Change {0};

    cout << "Enter Change: ";
    cin >> Change;

    FiveDollars = Change / FIVE_DOLLAR_VALUE;
    Change %= FIVE_DOLLAR_VALUE;

    Dollars = Change / DOLLAR_VALUE;
    Change %= DOLLAR_VALUE;

    Quarters = Change / QUARTER_VALUE;
    Change %= QUARTER_VALUE;

    Dimes = Change / DIME_VALUE;
    Change %= DIME_VALUE;

    Nickels = Change / NICKLE_VALUE;
    Change %= NICKLE_VALUE;

    Pennies = Change / PENNY_VALUE;
    Change %= PENNY_VALUE;

    cout << "5 Dollar(s): " << FiveDollars << endl;
    cout << "Dollar(s): " << Dollars << endl;
    cout << "Quarter(s): " << Quarters << endl;
    cout << "Dime(s): " << Dimes << endl;
    cout << "Nickel(s): " << Nickels << endl;
    cout << "Penny(ies): " << Pennies << endl;

    return 0;
}