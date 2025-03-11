#include "../../00_std_lib_facilities.h"

struct X
{
    int val;
    void out(const string& s, int nv)
    {
        cerr << this << "->" << s << ": " << val << "(" << nv << ")" << endl;
    }
    X() // default constructor
    {
        out("x()", 0);
        val = 0;
    }
    X(int v)
    {
        val = v;
        out("X(int)", v);
    }
    X(const X& x) // copy constructor
    {
        val = x.val;
        out("X(X&) ", x.val);
    }
    X& operator=(const X& a) // copy assignment
    {
        out("X::operator=()", a.val);
        val = a.val;
        return *this;
    }
    ~X() // destructor
    {
        out("~X()", 0);
    }
};

X glob(2); // a global variable
X copy(X a)
{
    return a;
}
X copy2(X a)
{
    X aa = a;
    return aa;
}
X& ref_to(X& a)
{
    return a;
}
X* make(int i)
{
    X a(i);
    return new X(a);
}
struct XX
{
    X a;
    X b;
};

int main()
{
    cout << endl;
    cout << "================ Local Variable ================" << endl;
    X loc{4};
    cout << endl;

    cout << "=============== Copy Constructor ===============" << endl;
    X loc2{loc};
    cout << endl;

    cout << "================ Copy Assignment ===============" << endl;
    loc = X{5};
    cout << endl;

    cout << "==================== Copy() ====================" << endl;
    loc2 = copy(loc);
    cout << endl;

    cout << "==================== Copy2() ===================" << endl;
    loc2 = copy2(loc);
    cout << endl;

    cout << "===================== loc3 =====================" << endl;
    X loc3{6};
    cout << endl;

    cout << "=================== ref_to() ===================" << endl;
    X& r = ref_to(loc);
    cout << endl;

    cout << "================ delete make(7) ================" << endl;
    delete make(7);
    cout << endl;

    cout << "================ delete make(8) ================" << endl;
    delete make(8);
    cout << endl;

    cout << "================ default values ================" << endl;
    vector<X> v(4);
    cout << endl;

    cout << "==================== XX loc4 ===================" << endl;
    XX loc4;
    cout << endl;

    cout << "================ X on Free Store ===============" << endl;
    X* p = new X{9};
    cout << endl;

    cout << "=================== delete p ===================" << endl;
    delete p;
    cout << endl;

    cout << "============== array on Free Store =============" << endl;
    X* pp = new X[5];
    cout << endl;

    cout << "=================== delete[] ===================" << endl;
    delete[] pp;
    cout << endl;

    cout << "================ automatic delete ==============" << endl;
    return 0;
}