#include <iostream>
#include <vector>
#include <memory>
#include "Savings.h"
#include "Trust.h"
#include "Checking.h"

using namespace std;

void withdrawl(Account& account, double amount);
std::ostream& operator<<(std::ostream& os, const I_Printable& obj);

class Test
{
  private:
    int data;

  public:
    Test() : data{0}
    {
        cout << "Test Constructor (" << data << ")" << endl;
    }
    Test(int data) : data{data}
    {
        cout << "Test Constructor (" << data << ")" << endl;
    }
    int get_data() const
    {
        return data;
    }
    ~Test()
    {
        cout << "Test Destructor (" << data << ")" << endl;
    }
};

int main()
{
    Test* test1 = new Test{1000};
    delete test1;

    unique_ptr<Test> test2{new Test{100}};
    unique_ptr<Test> test3 = make_unique<Test>(1000);

    unique_ptr<Test> test4;
    // test4 = test2; // error: test2 is no longer in scope
    test4 = move(test2);
    if (!test2)
        cout << "test2 is nullptr" << endl; // test2 doesn't share pointer when it's moved()

    unique_ptr<Account> account1 = make_unique<Checking>();
    cout << *account1 << endl;

    vector<unique_ptr<Account>> accounts;

    accounts.push_back(make_unique<Checking>());
    accounts.push_back(make_unique<Savings>());
    accounts.push_back(make_unique<Trust>());

    for (const auto& account : accounts)
    {
        cout << *account << endl;
    }

    return 0;
}

void withdrawl(Account& account, double amount)
{
    account.withdraw(amount);
    cout << endl;
}

std::ostream& operator<<(std::ostream& os, const I_Printable& obj)
{
    obj.print(os); // uses polymorphism to with the friend to display correct message
    return os;
}