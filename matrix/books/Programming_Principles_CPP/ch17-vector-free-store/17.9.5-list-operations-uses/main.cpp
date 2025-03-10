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

Link* add(Link* startPoint, Link* p, Link* n) {
    if (n == nullptr) return p;
    if (p == nullptr) return n;

    n->prev = p;

    if (p->succ) p->succ->prev = n;

    n->succ = p->succ;
    p->succ = n;
    return startPoint;
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

void print_all(Link* p) {
    cout << "{";
    while (p) {
        cout << p->value;
        p = p->succ;
        if (p) cout << ", ";
    }
    cout << "}" << endl;
}

int main() {
    Link* norse_gods = new Link{"Thor"};
    norse_gods = insert(norse_gods, new Link{"Odin"});
    norse_gods = insert(norse_gods, new Link{"Zeus"});
    norse_gods = insert(norse_gods, new Link{"Freia"});
    
    Link* greek_gods = new Link{"Posiedon"};
    greek_gods = add(greek_gods, greek_gods, new Link{"Mars"});
    greek_gods = add(greek_gods, find(greek_gods, "Mars"), new Link{"Athena"});
    greek_gods = add(greek_gods, find(greek_gods, "Athena"), new Link{"Hera"});

    Link* p = find(greek_gods, "Mars");
    if (p) p->value = "Ares";

    Link* Zeus = find(norse_gods, "Zeus");
    if (Zeus) {
        if (Zeus == norse_gods) norse_gods = Zeus->succ;
        erase(Zeus);
        greek_gods = insert(greek_gods, Zeus);
    }

    print_all(norse_gods);
    print_all(greek_gods);

    return 0;
}