#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <list>

void display(const std::vector<int>& vec);
void test1();
void test2();
void test3();
void test4();
void test5();

int main() {
    test1();
    test2();
    test3();
    test4();
    test5();

    return 0;
}

void display(const std::vector<int>& vec) {
    std::cout << "[ ";
    for (auto const& i : vec) {
        std::cout << i << " ";
    }
    std::cout << "]" << std::endl;
}

void test1() {
    std::cout << "\n================== test1() ==================\n";
    std::vector<int> nums1{1, 2, 3, 4, 5};
    auto iterator = nums1.begin();  // point to 1
    std::cout << *iterator << std::endl;

    iterator++;  // point to 2
    std::cout << *iterator << std::endl;

    iterator += 2;  // point to 4
    std::cout << *iterator << std::endl;

    iterator -= 2;  // point to 2
    std::cout << *iterator << std::endl;

    iterator = nums1.end() - 1;  // point to 5
    std::cout << *iterator << std::endl;
}

void test2() {
    std::cout << "\n================== test2() ==================\n";

    std::vector<int> nums1{1, 2, 3, 4, 5};

    std::vector<int>::iterator iterator = nums1.begin();
    while (iterator != nums1.end()) {
        std::cout << *iterator << std::endl;
        iterator++;
    }

    while (iterator != nums1.end()) {
        *iterator = 0;
        iterator++;
    }

    display(nums1);
}

void test3() {
    std::cout << "\n================== test3() ==================\n";

    std::vector<int> nums1{1, 2, 3, 4, 5};

    std::vector<int>::const_iterator iterator = nums1.begin();
    // auto iterator = nums1.cbegin(); // notice cbegin() for auto with a const_iterator

    while (iterator != nums1.end()) {
        std::cout << *iterator << std::endl;
        iterator++;
    }

    iterator = nums1.begin();
    while (iterator != nums1.end()) {
        // *iterator = 0; // compile error - read only (const)
        iterator++;
    }
}

void test4() {
    std::cout << "\n================== test4() ==================\n";
    // more iterators
    // using a reverse iterator
    std::vector<int> vec{1, 2, 3, 4};
    auto it1 = vec.rbegin();  // reverse iterator over vector of ints starts at 4
    while (it1 != vec.rend()) {
        std::cout << *it1 << std::endl;
        it1++;
    }

    // const reverse iterator over a list
    std::list<std::string> name{"Larry", "Moe", "Curly"};
    auto it2 = name.crbegin();  // iterator over list of strings  point to Curly
    std::cout << *it2 << std::endl;
    it2++;  // point to Moe
    std::cout << *it2 << std::endl;

    // iterator over a map
    std::map<std::string, std::string> favorites{{"Frank", "C++"}, {"Bill", "Java"}, {"James", "Haskell"}};
    auto it3 = favorites.begin();  // iterator over map of string, string pairs
    while (it3 != favorites.end()) {
        std::cout << it3->first << " : " << it3->second << std::endl;
        it3++;
    }
}

void test5() {
    std::cout << "\n================== test5() ==================\n";
    // iterate over a subset of a container
    std::vector<int> vec{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    auto start = vec.begin() + 2;
    auto finish = vec.end() - 3;

    while (start != finish) {
        std::cout << *start << std::endl;
        start++;
    }
}
