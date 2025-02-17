#include <iostream>
#include <vector>

using namespace std;

/*
    Given a vector of integers named vec  that is provided for you, find the sum of the product of all pairs of vector
    elements. You should declare an integer variable named result  and store the final product in this variable.

    For example, given the vector  vec  to be {1, 2 , 3} , the possible pairs are (1,2), (1,3), and (2,3) .
    So the result would be (1*2) + (1*3) + (2*3)  which is 11 .

    Another example:
    Given the vector vec  to be {2, 4, 6, 8} , the possible pairs are (2,4), (2,6), (2,8), (4,6), (4,8), and (6,8) .
    So the result would be (2*4) + (2*6) + (2*8) + (4*6) + (4*8) + (6*8) which is 140 .

    If the vector is empty or has only 1  element then the result  should be 0 .

    You can find my solution by clicking on the solution.txt file on the left pane. But please make sure you give it a go
    yourself first, and only check the solution if you really get stuck.
*/

int main()
{
    vector<int> vec{2, 4, 6, 8, 10};

    int result{0};

    if (!vec.empty() && vec.size() > 0)
    {
        for (size_t pair1{0}; pair1 < vec.size(); pair1++)
        {
            for (size_t pair2{pair1 + 1}; pair2 < vec.size(); pair2++)
            {
                cout << "(" << vec.at(pair1) << "," << vec.at(pair2) << ")" << endl;
                result += vec.at(pair1) * vec.at(pair2);
                cout << "Result: " << result << endl;
            }
        }
    }

    return 0;
}