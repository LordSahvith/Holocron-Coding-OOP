#include <iostream>
#include <fstream>
#include <iomanip>

int main()
{
    std::ifstream in_file;
    std::string line;

    in_file.open("MyScript.txt");

    if (!in_file)
    {
        std::cerr << "Error reading file." << std::endl;
        return 1;
    }

    while (std::getline(in_file, line))
    {
        std::cout << line << std::endl;
    }

    // char c{};
    // while (in_file.get(c))
    // {
    //     std::cout << c;
    // }

    std::cout << std::endl;

    in_file.close();

    return 0;
}