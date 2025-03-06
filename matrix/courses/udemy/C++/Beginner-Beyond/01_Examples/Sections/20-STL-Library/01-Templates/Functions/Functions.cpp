#include <iostream>
#include <string>

struct Person
{
    std::string name;
    int age;

    bool operator<(const Person& rhs) const
    {
        return this->age < rhs.age;
    }
};

template <typename T> T min(T a, T b);
template <typename T1, typename T2> void func(T1 a, T2 b);
template <typename T> void MySwap(T& a, T& b);

std::ostream& operator<<(std::ostream& os, const Person& p);

void DefaultTemplates();

int main()
{
    DefaultTemplates();

    return 0;
}

template <typename T> T min(T a, T b)
{
    return (a < b) ? a : b;
}

template <typename T1, typename T2> void func(T1 a, T2 b)
{
    std::cout << a << " " << b << std::endl;
}

std::ostream& operator<<(std::ostream& os, const Person& p)
{
    os << p.name;
    return os;
}

template <typename T> void MySwap(T& a, T& b)
{
    T temp = a;
    a = b;
    b = temp;
}

void DefaultTemplates()
{
    std::cout << min<int>(2, 3) << std::endl;         // 2
    std::cout << min(2, 3) << std::endl;              // 2
    std::cout << min('A', 'B') << std::endl;          // A
    std::cout << min(12.5, 9.2) << std::endl;         // 9.2
    std::cout << min(5 + 2 * 2, 7 + 45) << std::endl; // 9

    Person p1{"savith", 33};
    Person p2{"bob", 55};
    Person p3 = min(p1, p2);
    std::cout << p3.name << " is younger" << std::endl;
    func(p1, p2);

    func<int, int>(10, 20);
    func(10, 20);
    func<char, double>('A', 12.4);
    func('A', 12.4);
    func(1000, "testing");
    func(2000, std::string{"Savith"});

    int x{100};
    int y{200};
    std::cout << x << " " << y << std::endl;
    MySwap(x, y);
    std::cout << x << " " << y << std::endl;
}
