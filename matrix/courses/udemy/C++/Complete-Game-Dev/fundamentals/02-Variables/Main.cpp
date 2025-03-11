#include <iostream>

int main()
{
    char cStyleString[] = "Hello World!";
    std::string cppStyleString = "Hello World!";
    int age = 2025;
    float temperature = 57.4;

    std::cout << cStyleString << std::endl;
    std::cout << cppStyleString << std::endl;
    std::cout << cppStyleString << " The year is: " << age << ", and it's " << temperature << " degrees." << std::endl;

    return 0;
}