// Critter Class

#include <string>

using std::string;

class Critter
{
  public:
    Critter(const string& = "");
    string GetName() const;

  private:
    string CritterName;
};