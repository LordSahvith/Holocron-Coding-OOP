// Critter Caretaker
// Simulates caring for a virtual pet

#include <iostream>

using namespace std;

class Critter
{
  public:
    Critter(int hunger = 0, int boredom = 0);
    void Talk();
    void Eat(int food = 4);
    void Play(int fun = 4);

  private:
    int Hunger;
    int Boredom;

    int GetMood() const;
    void PassTime(int time = 1);
};

Critter::Critter(int hunger, int boredom)
{
    Hunger = hunger;
    Boredom = boredom;
}

inline int Critter::GetMood() const
{
    return (Hunger + Boredom);
}

void Critter::PassTime(int time)
{
    Hunger += time;
    Boredom += time;
}

void Critter::Talk()
{
    cout << "I'm a critter and I feel ";
    int mood = GetMood();

    if (mood > 15)
    {
        cout << "mad.\n";
    }
    else if (mood > 10)
    {
        cout << "frustrated.\n";
    }
    else if (mood > 5)
    {
        cout << "okay.\n";
    }
    else
    {
        cout << "happy.\n";
    }

    PassTime();
}

void Critter::Eat(int food)
{
    cout << "eating..." << endl;

    Hunger -= food;

    if (Hunger < 0)
    {
        Hunger = 0;
    }

    PassTime();
}

void Critter::Play(int fun)
{
    cout << "playing...." << endl;

    Boredom -= fun;

    if (Boredom < 0)
    {
        Boredom = 0;
    }

    PassTime();
}

int main()
{
    Critter Maui;
    Maui.Talk();

    int choice;
    do
    {
        cout << "\nCritter Caretaker\n";
        cout << "0 - Quit\n";
        cout << "1 - Listen to your critter\n";
        cout << "2 - Feed your critter\n";
        cout << "3 - Play with your critter\n";

        cout << "\nChoice: ";
        cin >> choice;

        switch (choice)
        {
        case 0:
            cout << "Goodbye." << endl;
            break;
        case 1:
            Maui.Talk();
            break;
        case 2:
            Maui.Eat();
            break;
        case 3:
            Maui.Play();
            break;
        default:
            cout << "Sorry, but " << choice << " isn't a valid choice.\n";
        }
    } while (choice != 0);

    return 0;
}
