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

Link* add(Link* p, Link* n) {
    if (n == nullptr) return p;
    if (p == nullptr) return n;

    n->prev = p;

    if (p->succ) p->succ->prev = n;

    n->succ = p->succ;
    p->succ = n;
    return p;
}

Link* erase(Link* p) {
    if (p == nullptr) return nullptr;
    if (p->succ) p->succ->prev = p->prev;
    if (p->prev) p->prev->succ = p->succ;
    return p->succ;
}

Link* find(Link* p, const string& s) {
    while (p) {
        if (p->value == s) return p;
        p = p->succ;
    }
    return nullptr;  // return nullptr for not found
}

Link* advance(Link* p, int n) {
    if (p == nullptr) return nullptr;

    if (0 < n) {
        while (n--) {
            if (p->succ == nullptr) return nullptr;
            p = p->prev;
        }
    } else if (n < 0) {
        while (n++) {
            if (p->prev == nullptr) return nullptr;
            p = p->prev;
        }
    }
    return p;
}

int main() {
    Link* norse_gods = new Link{"Thor"};
    norse_gods = insert(norse_gods, new Link{"Odin"});
    norse_gods = insert(norse_gods, new Link{"Freia"});

    cout << norse_gods->value << endl;              // Freia
    cout << norse_gods->succ->value << endl;        // Odin
    cout << norse_gods->succ->succ->value << endl;  // Thor

    Link* greek_gods = new Link{"Hera"};
    greek_gods = add(greek_gods, new Link{"Athena"});
    greek_gods = add(greek_gods, new Link{"Mars"});

    cout << greek_gods->value << endl;
    cout << greek_gods->succ->value << endl;
    cout << greek_gods->succ->succ->value << endl;

    cout << find(greek_gods, "Mars")->value << endl;

    greek_gods = add(find(greek_gods, "Mars"), new Link{"Zeus"});

    cout << greek_gods->value << endl;
    cout << greek_gods->succ->value << endl;

    return 0;
}