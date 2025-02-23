// Generic Player Class

#include "GenericPlayer.h"

using std::cout;

GenericPlayer::GenericPlayer(const string& name)
{
    Name = name;
}

GenericPlayer::~GenericPlayer()
{}

bool GenericPlayer::IsBusted() const
{
    return (GetTotal() > 21);
}

void GenericPlayer::Bust() const
{
    cout << Name << " busts.\n";
}