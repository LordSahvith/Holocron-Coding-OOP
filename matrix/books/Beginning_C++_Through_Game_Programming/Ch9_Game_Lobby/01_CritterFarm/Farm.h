// Farm Class

#include <vector>

class Critter;

class Farm
{
  public:
    Farm(int spaces = 1);
    void Add(const Critter& aCritter);
    void RollCall() const;

  private:
    std::vector<Critter> Critters;
};