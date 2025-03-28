#include <iostream>
#include <map>

int main()
{
    // Arithmetic
    // +, -, *, /, %

    int a{10};
    int b{20};

    int c{a + b}; // 30
    int d{a - b}; // -10
    int e{a * b}; // 200
    int f{a / b}; // 0
    int g{a % b}; // 10

    std::cout << "c: " << c << std::endl;
    std::cout << "d: " << d << std::endl;
    std::cout << "e: " << e << std::endl;
    std::cout << "f: " << f << std::endl;
    std::cout << "g: " << g << std::endl;

    float aa{10};
    float bb{20};

    float cc{aa + bb}; // 30.0
    float dd{aa - bb}; // -10.0
    float ee{aa * bb}; // 200.0
    float ff{aa / bb}; // 0.5

    std::cout << "cc: " << cc << std::endl;
    std::cout << "dd: " << dd << std::endl;
    std::cout << "ee: " << ee << std::endl;
    std::cout << "ff: " << ff << std::endl;
}