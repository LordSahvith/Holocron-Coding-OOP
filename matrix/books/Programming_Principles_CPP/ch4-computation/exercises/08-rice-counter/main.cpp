#include "../../../00_std_lib_facilities.h"

int main()
{
    int sum{1};
    int squareCount1K{0};
    int squareCount1M{0};
    int squareCount1B{0};

    for (int i = 0; i < 30; i++)
    {
        sum += sum;

        cout << "sum (" << i << "): " << sum << endl;

        if (sum >= 1000 && sum <= 1024)
        {
            squareCount1K = i + 1;
        }
        if (sum >= 1'000'000 && sum <= 1'048'576)
        {
            squareCount1M = i + 1;
        }
        if (sum >= 1'000'000'000 && sum <= 1'073'741'824)
        {
            squareCount1B = i + 1;
        }
    }

    cout << "1Kth square: " << squareCount1K << endl;
    cout << "1Mth square: " << squareCount1M << endl;
    cout << "1Bth square: " << squareCount1B << endl;
    cout << "Rice Grains: " << sum << endl;
}