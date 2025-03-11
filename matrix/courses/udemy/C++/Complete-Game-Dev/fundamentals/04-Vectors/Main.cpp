#include <iostream>
#include <vector>

int main()
{
    // array doesn't change size
    int IDs[]{1234, 1334, 1434};

    std::vector<int> IDVec{1234, 1334, 1434};

    std::cout << "the first of IDs: " << IDs[0] << std::endl;
    std::cout << "the first of IDVec: " << IDVec[0] << std::endl;

    std::cout << "the last of IDs: " << IDs[sizeof(IDs) / sizeof(int) - 1] << std::endl;
    std::cout << "the last of IDVec: " << IDVec.back() << std::endl;

    std::cout << "the size of IDs: " << sizeof(IDs) / sizeof(int) << std::endl;
    std::cout << "the size of IDVec: " << IDVec.size() << std::endl;

    // vectors can grow and shrink
    // grow
    IDVec.push_back(1534); // adds to back of vector
    std::cout << "the last of IDVec: " << IDVec.back() << std::endl;
    IDVec.insert(IDVec.begin(), 1134); // inserts at specified location
    std::cout << "the first of IDVec: " << IDVec.front() << std::endl;

    // shrink
    IDVec.pop_back(); // removes the back (last) of vector
    std::cout << "the last of IDVec: " << IDVec.back() << std::endl;
    std::cout << "the second of IDVec: " << IDVec[1] << std::endl;
    IDVec.erase(IDVec.begin() + 1); // removes from specified location
    std::cout << "the second of IDVec: " << IDVec[1] << std::endl;

    // .at() does bounds checking
    try
    {
        int temp{IDVec.at(5)}; // throws exception: out of bounds
        std::cout << "doesn't exist: " << temp << std::endl;
    }
    catch (const std::exception& e)
    {
        std::cerr << e.what() << std::endl; // error: vector::_M_range_check: __n (which is 5) >= this->size() (which is 3)
    }

    // [] (subscripting) doesn't bounds check
    try
    {
        int temp{IDVec[5]};
        std::cout << "doesn't exist: " << temp << std::endl; // gives garbage data
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n'; // Won't execute
    }
    

    return 0;
}