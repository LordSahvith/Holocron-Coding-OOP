#include "../../00_std_lib_facilities.h"

class Link
{
  public:
    string value;
    Link(const string& v, Link* p = nullptr, Link* s = nullptr) : value{v}, previous{p}, next{s}
    {
    }

    Link* insert(Link* newLink);           // insert newLink before this object
    Link* add(Link* newLink);              // insert newLink after this objec
    Link* erase();                         // remove object from list
    Link* find(const string& valueToFind); // find valueToFind in list

    Link* get_next() const
    {
        return next;
    }
    Link* get_previous() const
    {
        return previous;
    }

  private:
    Link* previous;
    Link* next;
};

Link* Link::insert(Link* newLink)
{
    if (newLink == nullptr)
    {
        return this;
    }
    newLink->next = this;
    if (previous)
    {
        previous->next = newLink;
    }
    newLink->previous = previous;
    previous = newLink;
    return newLink;
}

Link* Link::add(Link* newLink)
{
    if (newLink == nullptr)
    {
        return this;
    }
    newLink->previous = this;

    if (next)
    {
        next->previous = newLink;
    }

    newLink->next = next;
    next = newLink;
    return newLink;
}

Link* Link::erase()
{
    if (next)
    {
        next->previous = previous;
    }
    if (previous)
    {
        previous->next = next;
    }
    return next;
}

Link* Link::find(const string& valueToFind)
{
    Link* listPtr = this;
    while (listPtr)
    {
        if (listPtr->value == valueToFind)
            return listPtr;
        listPtr = listPtr->get_next();
    }
    return nullptr; // return nullptr for not found
}

void print_all(Link* p)
{
    cout << "{";
    while (p)
    {
        cout << p->value;
        p = p->get_next();
        if (p)
        {
            cout << ", ";
        }
    }
    cout << "}" << endl;
}

int main()
{
    Link* norse_gods = new Link{"Thor"};
    norse_gods = norse_gods->insert(new Link{"Odin"});
    norse_gods = norse_gods->insert(new Link{"Zeus"});
    norse_gods = norse_gods->insert(new Link{"Freia"});

    Link* greek_gods = new Link{"Hera"};
    greek_gods = greek_gods->insert(new Link{"Athena"});
    greek_gods = greek_gods->insert(new Link{"Mars"});
    greek_gods = greek_gods->insert(new Link{"Poseidon"});

    Link* Mars = greek_gods->find("Mars");
    if (Mars)
    {
        Mars->value = "Ares";
    }

    Link* Zeus = norse_gods->find("Zeus");
    if (Zeus)
    {
        if (Zeus == norse_gods)
        {
            norse_gods = Zeus->get_next();
        }
        Zeus->erase();
        greek_gods = greek_gods->insert(Zeus);
    }

    print_all(norse_gods);
    print_all(greek_gods);

    return 0;
}