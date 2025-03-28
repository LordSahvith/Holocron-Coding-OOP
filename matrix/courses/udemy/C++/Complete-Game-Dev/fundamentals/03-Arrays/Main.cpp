#include <iostream>

int main()
{
    // array of strings - [] denotes array
    std::string employees[]{"steve", "bob", "allen"};

    std::cout << employees[0] << std::endl; // steve
    std::cout << employees[1] << std::endl; // bob
    std::cout << employees[2] << std::endl; // allen

    // throws: array out of bounds call
    // std::cout << employees[3] << std::endl; // there is no 4th index

    employees[2] = "savith";
    std::cout << employees[2] << std::endl; // savith

    return 0;
}