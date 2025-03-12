#include "../../../../00_std_lib_facilities.h"

int main()
{
    int pennies{0};
    cout << "Enter number of pennies: ";
    cin >> pennies;

    int nickels{0};
    int dimes{0};
    int quaters{0};
    int dollars{0};
    const int NICKEL_VALUE{5};
    const int DIME_VALUE{10};
    const int QUATERS_VALUE{25};
    const int DOLLAR_VALUE{100};

    dollars = pennies / DOLLAR_VALUE;
    pennies = pennies % DOLLAR_VALUE;

    cout << "You have: $" << dollars << "." << pennies << endl;

    quaters = pennies / QUATERS_VALUE;
    pennies = pennies % QUATERS_VALUE;

    dimes = pennies / DIME_VALUE;
    pennies = pennies % DIME_VALUE;

    nickels = pennies / NICKEL_VALUE;
    pennies = pennies % NICKEL_VALUE;
    cout << "dollar" << (dollars > 1 ? "s: " : ": ") << dollars << endl;
    cout << "quarter" << (quaters > 1 ? "s: " : ": ") << quaters << endl;
    cout << "dime" << (dimes > 1 ? "s: " : ": ") << dimes << endl;
    cout << "nickel: " << nickels << endl; // no need to add (s) cuz 2 nickels is a dime
    cout << "penn" << (pennies > 1 ? "ies: " : "y: ") << pennies << endl;
}