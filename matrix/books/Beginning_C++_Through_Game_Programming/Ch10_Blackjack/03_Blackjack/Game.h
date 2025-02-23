// Game Class Header

#include <vector>
#include <string>
#include "Player.h"
#include "Deck.h"
#include "House.h"

using std::vector;
using std::string;

class Game
{
public:
    Game(const vector<string>& names);
    ~Game();

    // plays the game of blackjack
    void Play();

private:
    Deck GameDeck;
    House House;
    vector<Player> Players;
};