#include <iostream>
#include <string>

using namespace std;

struct LocationVector
{
    float X;
    float Y;
    float Z;
};

struct Player
{
    string Name;
    float Health;
    float Damage;
    int Level;

    LocationVector Location{0.0, 0.0, 0.0};

    void TakeDamage(float dmg)
    {
        Health -= dmg;
    }

    int GetLevel()
    {
        return Level;
    }

    void DisplayLocation()
    {
        cout << "Location.X: " << Location.X << endl;
        cout << "Location.Y: " << Location.Y << endl;
        cout << "Location.Z: " << Location.Z << endl;
    }
};

int main()
{
    Player p1;
    p1.Name = "Savith";
    p1.Health = 100;
    p1.Damage = 25;
    p1.Level = 1;

    cout << "p1 level: " << p1.GetLevel() << endl;
    p1.TakeDamage(50.0);
    cout << "p1 takes damage: " << 50.0 << endl;
    cout << "p1 health: " << p1.Health << endl;
    p1.DisplayLocation();

    Player p2{"Lord Savith", 150, 50, 5, {1.0, 2.0, 3.0}};
    cout << "p2 level: " << p2.GetLevel() << endl;
    p2.DisplayLocation();

    return 0;
}