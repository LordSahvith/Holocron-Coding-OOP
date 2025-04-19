#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>
#include <sstream>
#include <cstdlib>
#include <stdexcept>
#include <vector>

std::vector<std::string> ReadFile(std::string fileName, std::vector<std::string>& counterRef)
{
    std::ifstream inStream{fileName};
    if (!inStream)
    {
        std::cout << "Can't open file " << fileName << std::endl;
    }

    std::string text;
    int count;
    while (inStream >> text >> count)
    {
        count++;
        std::string lineOfText{text + ' ' + std::to_string(count) + '\n'};
        counterRef.push_back(lineOfText);
    }

    return counterRef;
}

int main()
{
    std::string fileName{"in-file.txt"};

    std::vector<std::string> counter;
    counter = ReadFile(fileName, counter);

    std::ofstream outStream{fileName};
    if (!outStream)
    {
        std::cout << "Can't write to file " << fileName << std::endl;
    }

    for (std::string count : counter)
    {
        outStream << count;
    }
}