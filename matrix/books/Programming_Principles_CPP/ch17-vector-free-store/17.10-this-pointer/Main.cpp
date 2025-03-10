#include "../../00_std_lib_facilities.h"

class Link {
   public:
    string value;
    Link(const string& v, Link* p = nullptr, Link* s = nullptr) : value{v}, previous{p}, next{s} {}

    Link* insert(Link* newLink);                  // insert newLink before this object
    Link* add(Link* newLink);                     // insert newLink after this objec
    Link* erase();                                // remove object from list
    Link* find(const string& value);              // find value in list
    const Link* find(const string& value) const;  // find value in const list

    Link* advance(int num) const;  // move num positions in list

    Link* get_next() const { return next; }
    Link* get_previous() const { return previous; }

   private:
    Link* previous;
    Link* next;
};

Link* Link::insert(Link* newLink) {
    if (newLink == nullptr) return this;
    newLink->next = this;
    if (previous) previous->next = newLink;
    newLink->previous = previous;
    previous = newLink; 
    return newLink;
}

Link* add(Link* startPoint, Link* p, Link* n) {
    if (n == nullptr) return p;
    if (p == nullptr) return n;

    n->previous = p;

    if (p->next) p->next->previous = n;

    n->next = p->next;
    p->next = n;
    return startPoint;
}

Link* erase(Link* p) {
    if (p == nullptr) return nullptr;
    if (p->next) p->next->previous = p->previous;
    if (p->previous) p->previous->next = p->next;
    return p->next;
}

Link* find(Link* p, const string& s) {
    while (p) {
        if (p->value == s) return p;
        p = p->next;
    }
    return nullptr;  // return nullptr for not found
}

Link* advance(Link* p, int n) {
    if (p == nullptr) return nullptr;

    if (0 < n) {
        while (n--) {
            if (p->next == nullptr) return nullptr;
            p = p->previous;
        }
    } else if (n < 0) {
        while (n++) {
            if (p->previous == nullptr) return nullptr;
            p = p->previous;
        }
    }
    return p;
}

void print_all(Link* p) {
    cout << "{";
    while (p) {
        cout << p->value;
        p = p->next;
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
        if (Zeus == norse_gods) norse_gods = Zeus->next;
        erase(Zeus);
        greek_gods = insert(greek_gods, Zeus);
    }

    print_all(norse_gods);
    print_all(greek_gods);

    return 0;
}