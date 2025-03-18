#include "../../../00_std_lib_facilities.h"

class Token
{
  public:
    char kind;                                      // kind of token
    double value;                                   // for numbers: a value
    Token(char k) : kind{k}, value{0.0} {};         // construct from one value
    Token(char k, double v) : kind{k}, value{v} {}; // construct from two values
};

Token get_token();   // read characters and compose tokens
double expression(); // deal with + and -
double term();       // deal with *, /, and %
double primary();    // deal with numbers and parentheses

int main()
{
}