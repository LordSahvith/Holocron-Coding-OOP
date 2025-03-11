#include <iostream>

int main()
{
    std::string cppStyleString = "Hello World!";
    int age = 2025;
    float temperature = 57.4;

    char character = 'A'; // single quotes denotes a character

    /*
        c style strings except String Literals (double quotes) and converts to a
        Character Array (ex. ['H', 'e', 'l', 'l', 'o', ' ', 'W', 'o', 'r', 'l', 'd', '\0'])
    */
    char cStyleString[] = "Hello World!";

    bool isLightOn = true; // C++ uses binary for bools (true: 1, false: 0)

    std::cout << cppStyleString << " The year is: " << age << ", and it's " << temperature << " degrees." << std::endl;
    std::cout << character << std::endl;
    std::cout << cStyleString << std::endl;
    std::cout << "Is Light On: " << isLightOn << std::endl;

    std::cout << std::endl;

    std::cout << "the size of c++ string is: " << sizeof(std::string) << std::endl;
    std::cout << "the size of int is: " << sizeof(int) << std::endl;
    std::cout << "the size of float is: " << sizeof(float) << std::endl;
    std::cout << "the size of double is: " << sizeof(double) << std::endl;
    std::cout << "the size of char is: " << sizeof(char) << std::endl;
    std::cout << "the size of bool is: " << sizeof(bool) << std::endl;

    return 0;
}