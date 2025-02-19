// Game Stats
// Demonstrates declaring and initializing variables

#include <iostream>

using namespace std;

int main()
{
    const int ALIEN_POINTS = 150;
    int aliendsKilled = 10;
    int score = aliendsKilled * ALIEN_POINTS;
    cout << "score: " << score << endl;

    enum difficulty
    {
        NOVICE,
        EASY,
        NORMAL,
        HARD,
        UNEATABLE
    };
    difficulty myDifficulty = EASY;
    cout << "difficulty: " << myDifficulty << endl;

    enum shipCost
    {
        FIGHTER_COST = 25,
        BOMBER_COST,
        CRUISER_COST = 50
    };
    shipCost myShipCost = BOMBER_COST;
    cout << "\nTo upgrade my ship to a Cruiser will cost " << (CRUISER_COST - myShipCost) << " Resource Points.\n";

    return 0;
}