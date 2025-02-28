// Blackjack
// Classic Casino Card Game
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <ctime>
#include "Game.h"
#include "Card.h"

using std::cin;
using std::cout;
using std::endl;

// function prototypes
ostream& operator<<(ostream& os, const Card& card);
ostream& operator<<(ostream& os, const GenericPlayer& genericPlayer);

int main()
{
    cout << "Welcome to Blackjack!\n\n";

    int numPlayers = 0;
    while (numPlayers < 1 || numPlayers > 7)
    {
        cout << "How many player? (1 - 7): ";
        cin >> numPlayers;
    }

    vector<string> names;
    string name;
    for (int i = 0; i < numPlayers; ++i)
    {
        cout << "Enter player name: ";
        cin >> name;
        names.push_back(name);
    }

    cout << endl;

    // the game loop
    Game game = Game(names);
    char again = 'y';
    while (again != 'n' && again != 'N')
    {
        game.Play();
        cout << "\nDo you want to play again? (Y/N): ";
        cin >> again;
    }

    return 0;
}

ostream& operator<<(ostream& os, const Card& card)
{
    const string RANKS[] = {"0", "A", "2", "3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K"};
    const string SUITS[] = {"c", "d", "h", "s"};

    if (card.isFaceUp)
    {
        os << RANKS[card.Rank] << SUITS[card.Suit];
    }
    else
    {
        os << "XX";
    }

    return os;
}

ostream& operator<<(ostream& os, const GenericPlayer& genericPlayer)
{
    os << genericPlayer.Name << ":\t";

    vector<Card*>::const_iterator card;
    if (!genericPlayer.Cards.empty())
    {
        for (card = genericPlayer.Cards.begin(); card <= genericPlayer.Cards.end(); ++card)
        {
            os << *(*card) << "\t";
        }

        if (genericPlayer.GetTotal() != 0)
        {
            cout << "(" << genericPlayer.GetTotal() << ")";
        }
    }
    else
    {
        os << "<empty>";
    }

    return os;
}
