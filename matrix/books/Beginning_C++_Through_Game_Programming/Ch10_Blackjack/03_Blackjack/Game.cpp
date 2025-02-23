// Game Class

#include "Game.h"
#include <ctime>
#include <iostream>

using std::cout;
using std::endl;

Game::Game(const vector<string>& names)
{
    // create a vector fo players from a vector of names
    vector<string>::const_iterator name;
    for (name = names.begin(); name != names.end(); ++name)
    {
        Players.push_back(Player(*name));
    }

    // seed the random number generator
    srand(static_cast<unsigned int>(time(0)));
    GameDeck.Populate();
    GameDeck.Shuffle();
}

Game::~Game()
{
}

void Game::Play()
{
    // Deal initial 2 cards to everyone
    vector<Player>::iterator player;
    for (int i = 0; i < 2; ++i)
    {
        for (player = Players.begin(); player != Players.end(); ++player)
        {
            GameDeck.Deal(*player);
        }
        GameDeck.Deal(House);
    }

    // HIde house's first card
    House.FlipFirstCard();

    // display everyone's hand
    for (player = Players.begin(); player != Players.end(); ++player)
    {
        cout << *player << endl;
    }

    cout << House << endl;

    // deal additional cards to players
    for (player = Players.begin(); player != Players.end(); ++player)
    {
        GameDeck.AdditionalCards(*player);
    }

    // reveal house's first card
    House.FlipFirstCard();
    cout << endl << House;

    // deal additionla cards to house
    GameDeck.AdditionalCards(House);

    if (House.IsBusted())
    {
        // everyone still playing wins
        for (player = Players.begin(); player != Players.end(); ++player)
        {
            if (!(player->IsBusted()))
            {
                player->Win();
            }
        }
    }
    else
    {
        // compare each player still playing to house
        for (player = Players.begin(); player != Players.end(); ++player)
        {
            if (!(player->IsBusted()))
            {
                if (player->GetTotal() > House.GetTotal())
                {
                    player->Win();
                }
                else if (player->GetTotal() < House.GetTotal())
                {
                    player->Lose();
                }
                else
                {
                    player->Push();
                }
            }
        }
    }

    // removes everyone's cards
    for (player = Players.begin(); player != Players.end(); ++player)
    {
        player->Clear();
    }

    House.Clear();
}