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
    int count1;
    int count2;
    while (inStream >> count1 >> text >> count2)
    {
        count1++;
        count2++;
        std::string lineOfText{std::to_string(count1) + ' ' + text + ' ' + std::to_string(count2)};
        counterRef.push_back(lineOfText);
    }

    return counterRef;
}

void WriteFile(std::string fileName, std::vector<std::string>& counterRef)
{
    std::ofstream outStream{fileName};
    if (!outStream)
    {
        std::cout << "Can't write to file " << fileName << std::endl;
    }

    for (std::string count : counterRef)
    {
        outStream << count;
    }
}

int main()
{
    std::string fileName{"deaths.txt"};

    std::vector<std::string> counter;
    counter = ReadFile(fileName, counter);

    WriteFile(fileName, counter);
}