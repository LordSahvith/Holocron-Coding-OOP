#include <iostream>

int main()
{
    int FavoriteNumber;

    std::cout << "Enter your favorite number between 1 and 100: ";
    std::cin >> FavoriteNumber;
    std::cout << "No way! " << FavoriteNumber << " is my favorite too!" << std::endl; 

    return 0;
}