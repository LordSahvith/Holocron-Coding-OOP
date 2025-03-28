#include <iostream>
#include <map>

int main()
{
    // map: key/value pair
    std::map<std::string, int> IDs{{"Savith", 1234}, {"Bobby", 1334}};

    std::cout << "Savith's id: " << IDs["Savith"] << std::endl; // 1234

    IDs["Savith"] = 1334;
    std::cout << "Savith's id: " << IDs["Savith"] << std::endl; // 1334

    IDs.insert({"Bruce", 1434});
    std::cout << "Bruce's id: " << IDs["Bruce"] << std::endl; // adds Bruce to end of Map

    std::cout << "size of IDs: " << IDs.size() << std::endl; // 3
    IDs.erase("Bobby");
    std::cout << "size of IDs: " << IDs.size() << std::endl;  // 2
    std::cout << "Bobby's id: " << IDs["Bobby"] << std::endl; // if doesn't exist: inserts {"Bobby", 0} to back of Map
    std::cout << "size of IDs: " << IDs.size() << std::endl;  // 3

    IDs.clear();                                             // removes everything
    std::cout << "size of IDs: " << IDs.size() << std::endl; // 0

    auto loc = IDs.find("Savith");                                // returns iterator
    bool doesExist = loc != IDs.end();                            // does Savith exist
    std::cout << "Does Savith exist: " << doesExist << std::endl; // 0 (false)

    return 0;
}