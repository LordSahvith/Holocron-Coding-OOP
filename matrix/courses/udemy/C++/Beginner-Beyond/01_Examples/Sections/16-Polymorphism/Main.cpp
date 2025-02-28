#include <iostream>
#include "Savings.h"
#include "Trust.h"
#include "Checking.h"

using namespace std;

int main()
{
    cout << "\n======= Pointers =======\n";
    Account* pt1 = new Account();
    Account* pt2 = new Checking();
    Account* pt3 = new Savings();
    Account* pt4 = new Trust();

    pt1->withdraw(1000);
    pt2->withdraw(1000);
    pt3->withdraw(1000);
    pt4->withdraw(1000);

    delete pt1;
    delete pt2;
    delete pt3;
    delete pt4;

    return 0;
}