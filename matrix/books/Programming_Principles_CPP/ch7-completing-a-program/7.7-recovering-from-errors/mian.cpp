#include "../../00_std_lib_facilities.h"
#include <cmath>

const char number{'n'};
const char quit{'q'};
const char print{';'};
const string result{"= "};

class Token
{
  public:
    char kind;                                      // kind of token
    double value;                                   // for numbers: a value
    Token(char k) : kind{k}, value{0.0} {};         // construct from one value
    Token(char k, double v) : kind{k}, value{v} {}; // construct from two values
};

class Token_stream
{
  public:
    Token get();
    void putback(Token token);
    void ignore(char tokenType); // discard characters up to and including a tokenType

  private:
    bool full{false};
    Token buffer{0};
};

void Token_stream::putback(Token token)
{
    if (full)
    {
        error("putback() into a full buffer");
    }
    buffer = token;
    full = true;
}

Token Token_stream::get()
{
    if (full)
    {
        full = false;
        return buffer;
    }

    char ch;
    cin >> ch; // note that >> skips whitespace (space, newline, tab, etc.)

    switch (ch)
    {
        case print:
        case quit:
        case '%':
        case '(':
        case ')':
        case '+':
        case '-':
        case '*':
        case '/':
            return Token{ch}; // let each character represent itself
        case '.':
        case '0':
        case '1':
        case '2':
        case '3':
        case '4':
        case '5':
        case '6':
        case '7':
        case '8':
        case '9': {
            cin.putback(ch); // put digit back into the input stream
            double val;
            cin >> val;                // read a floating-point number
            return Token(number, val); // let 'n' represent "a number"
        }
        default:
            error("Bad token");
            return Token('z');
    }
}

void Token_stream::ignore(char tokenType)
{
    if (full && tokenType == buffer.kind)
    {
        full = false;
        return;
    }

    full = false;

    // now search input
    char ch{0};
    while (cin >> ch)
    {
        if (ch == tokenType)
        {
            return;
        }
    }
}

double expression(); // deal with + and -
double term();       // deal with *, /, and %
double primary();    // deal with numbers and parentheses
void calculate();    // expression evaluation loop
void clean_up_mess();

Token_stream token_stream;

int main()
{
    try
    {
        calculate();
        return 0;
    }
    catch (exception& e)
    {
        std::cerr << e.what() << endl;
        return 1;
    }
}

double expression()
{
    double left{term()};             // read and evaluate an Expression
    Token token{token_stream.get()}; // get the next token
    while (true)
    {
        switch (token.kind) // see which kind of token it is
        {
            case '+':
                left += term(); // evaluate Term and add
                token = token_stream.get();
                break;
            case '-':
                left -= term(); // evaluate Term and subtract
                token = token_stream.get();
                break;
            default:
                token_stream.putback(token);
                return left; // return the value of the Expression
        }
    }
}

double term()
{
    double left{primary()};          // read and evaluate an Expression
    Token token{token_stream.get()}; // get the next token
    while (true)
    {
        switch (token.kind) // see which kind of token it is
        {
            case '*':
                left *= primary(); // evaluate Primary and multiply
                token = token_stream.get();
                break;
            case '/':
                left /= primary(); // evaluate Primary and divide
                if (left == 0)
                {
                    error("divide by zero");
                }
                token = token_stream.get();
                break;
            case '%': {
                double d = primary();
                if (d == 0)
                {
                    error("%: divide by zero");
                }
                left = fmod(left, d);
                token = token_stream.get();
                break;
            }
            default:
                token_stream.putback(token);
                return left; // return the value of the Expression
        }
    }
}

double primary()
{
    Token token{token_stream.get()};
    switch (token.kind)
    {
        case '(': { // handle '(' expression ')'
            double expr{expression()};
            token = token_stream.get();
            if (token.kind != ')')
            {
                error("')' expected");
                return expr;
            }
        }
        case number:
            return token.value; // return the number's value
        case '-':
            return -primary();
        case '+':
            return primary();
        default:
            error("primary expected");
            return 0.0;
    }
}

void calculate()
{
    while (cin)
    {
        try
        {

            Token token = token_stream.get();

            while (token.kind == print)
            {
                token = token_stream.get(); // eat ';'
            }

            if (token.kind == quit)
            {
                return;
            }

            token_stream.putback(token);
            cout << result << expression() << endl;
        }
        catch (const std::exception& e)
        {
            std::cerr << e.what() << endl;
            clean_up_mess();
        }
    }
}

void clean_up_mess()
{
    token_stream.ignore(print);
}
