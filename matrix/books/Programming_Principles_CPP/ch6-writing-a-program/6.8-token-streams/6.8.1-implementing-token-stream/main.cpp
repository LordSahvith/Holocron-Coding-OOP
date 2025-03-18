#include "../../../00_std_lib_facilities.h"

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

Token get_token();   // read characters and compose tokens
double expression(); // deal with + and -
double term();       // deal with *, /, and %
double primary();    // deal with numbers and parentheses

Token_stream token_stream;

int main()
{
    double val{0.0};
    try
    {
        while (cin)
        {
            Token token = token_stream.get();
            if (token.kind == 'q')
            {
                break;
            }
            if (token.kind == ';')
            {
                cout << "=" << val << endl;
            }
            else
            {
                token_stream.putback(token);
            }
            val = expression();
        }
    }
    catch (exception& e)
    {
        std::cerr << e.what() << endl;
        return 1;
    }
}

Token get_token()
{
    char ch;
    cin >> ch; // note that >> skips whitespace (space, newline, tab, etc.)

    switch (ch)
    {
            // not yet   case ';':    // for "print"
            // not yet   case 'q':    // for "quit"
        case '(':
        case ')':
        case '+':
        case '-':
        case '*':
        case '/':
            return Token(ch); // let each character represent itself
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
            cin >> val;             // read a floating-point number
            return Token('n', val); // let '8' represent "a number"
        }
        default:
            error("Bad token");
            return Token(ch);
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
                token = get_token();
                break;
            case '-':
                left -= term(); // evaluate Term and subtract
                token = get_token();
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
            token = get_token();
            if (token.kind != ')')
            {
                error("')' expected");
                return expr;
            }
        }
        case 'n':               // 'n' for number
            return token.value; // return the number's value
        default:
            error("primary expected");
            return 0.0;
    }
}