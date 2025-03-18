#include "../../../00_std_lib_facilities.h"

class Token
{
  public:
    char kind;                                      // kind of token
    double value;                                   // for numbers: a value
    Token(char k) : kind{k}, value{0.0} {};         // construct from one value
    Token(char k, double v) : kind{k}, value{v} {}; // construct from two values
};

Token get_token();

vector<Token> tokenVec;

int main()
{
  while (cin)
  {
    Token t = get_token();
    tokenVec.push_back(t);
  }

  for (size_t i = 0; i < tokenVec.size(); i++)
  {
    if (tokenVec[i].kind == '*')
    {
      double d = tokenVec[i - 1].value * tokenVec[i + 1].value;
    }
  }
}