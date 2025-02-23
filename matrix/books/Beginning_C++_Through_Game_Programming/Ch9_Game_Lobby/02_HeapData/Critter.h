// Critter Class Header

#include <string>

using std::string;

class Critter
{
  public:
    Critter(const string& name = "", int age = 0);
    ~Critter();                                       // Destructor prototype
    Critter(const Critter& copy);                     // Copy contructor prototype
    // Critter& Critter::operator=(const Critter& copy); // overloaded assignment op
    void Greet() const;

  private:
    string* Name;
    int Age;
};