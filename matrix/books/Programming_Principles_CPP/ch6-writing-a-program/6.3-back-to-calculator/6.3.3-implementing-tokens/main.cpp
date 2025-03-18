#include "../../../00_std_lib_facilities.h"

class Token
{
  public:
    char kind;                                      // kind of token
    double value;                                   // for numbers: a value
    Token(char k) : kind{k}, value{0.0} {};         // construct from one value
    Token(char k, double v) : kind{k}, value{v} {}; // construct from two values
};

int main()
{
    Token t1{'+'};       // initlialize t1 so that t1.kind is '+' and t1.value is 0.0
    Token t2{'n', 11.5}; // initialize t2 so that t2.kind is 'n' and t2.value is 11.5
    // Token t3;            // error: no matching function for call to 'Token::Token()'
}