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

Token get_token()
{
    return Token('n', 0.0);
}

double expression()
{
    double left{term()};       // read and evaluate an Expression
    Token token = get_token(); // get the next token
    while (true)
    {
        switch (token.kind) // see which kind of token it is
        {
            case '+':
                left += term(); // evaluate Term and add
                token = get_token();
                break;
            case '-':
                left -= term(); // evaluate Term and subtract
                token = get_token();
                break;
            default:
                return left; // return the value of the Expression
        }
    }
}

double term()
{
    double left{primary()};    // read and evaluate an Expression
    Token token = get_token(); // get the next token
    while (true)
    {
        switch (token.kind) // see which kind of token it is
        {
            case '*':
                left *= primary(); // evaluate Primary and multiply
                token = get_token();
                break;
            case '/':
                left /= primary(); // evaluate Primary and divide
                if (left == 0)
                {
                    error("divide by zero");
                }
                token = get_token();
                break;
            default:
                return left; // return the value of the Expression
        }
    }
}

double primary()
{
    return 0.0;
}