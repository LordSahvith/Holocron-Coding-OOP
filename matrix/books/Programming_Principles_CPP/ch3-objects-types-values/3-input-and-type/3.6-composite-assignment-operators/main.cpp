#include <iostream>

int main()
{

    int counter = 1;

    counter = counter + 1; // 2
    ++counter; // 3

    int a = 0;
    int b = 0;
    int c = 2;

    a += 7; // means a = a + 7
    b -= 9; // -9
    c *= 2; // 4

    std::cout << "a: " << a << std::endl;
    std::cout << "b: " << b << std::endl;
    std::cout << "c: " << c << std::endl;

    return 0;
}