#include "../../00_std_lib_facilities.h"

struct Link {
    string value;
    Link* prev;
    Link* succ;
    Link(const string& v, Link* p = nullptr, Link* s = nullptr) : value{v}, prev{p}, succ{s} {}
};

Link* insert(Link* p, Link* n) {
    if (n == nullptr) return p;
    if (p == nullptr) return n;

    n->succ = p;
    
    if (p->prev) p->prev->succ = n;

    n->prev = p->prev;
    p->prev = n;
    return n;
}

int main() {
    Link* norse_gods = new Link{"Thor"};
    norse_gods = insert(norse_gods, new Link{"Odin"});
    norse_gods = insert(norse_gods, new Link{"Freia"});

    cout << norse_gods->value << endl;              // Freia
    cout << norse_gods->succ->value << endl;        // Odin
    cout << norse_gods->succ->succ->value << endl;  // Thor

    return 0;
}