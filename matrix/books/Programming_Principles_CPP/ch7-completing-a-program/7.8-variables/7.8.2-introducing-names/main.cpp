#include "../../../00_std_lib_facilities.h"
#include <cmath>

const char number{'n'};
const char quit{'q'};
const char print{';'};
const string result{"= "};
const char name{'a'};
const char let{'L'};
const string declkey{"let"};

class Variable
{
  public:
    string name;
    double value;
};

class Token
{
  public:
    char kind;    // kind of token
    double value; // for numbers: a value
    string name;
    Token() : kind{0} {};                                 // default constructor
    Token(char ch) : kind{ch} {};                         // construct from one value
    Token(char ch, double val) : kind{ch}, value{val} {}; // construct from two values
    Token(char ch, string n) : kind{ch}, name{n} {};
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
            if (isalpha(ch))
            {
                string s;
                s += ch;
                while (cin.get(ch) && (isalpha(ch) || isdigit(ch)))
                {
                    s += ch;
                }

                cin.putback(ch);
                if (s == declkey)
                {
                    return Token{let};
                }
                return Token{name, s};
            }
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
double statement();
void calculate(); // expression evaluation loop
void clean_up_mess();
double get_value(string s);
void set_value(string s, double d);
bool is_declared(string var);
double define_name(string var, double val);
double declaration();

Token_stream token_stream;
vector<Variable> var_table;

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

double statement()
{
    Token token = token_stream.get();
    switch (token.kind)
    {
        case let:
            return declaration();
        default:
            token_stream.putback(token);
            return expression();
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
            cout << result << statement() << endl;
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

double get_value(string s)
{
    for (const Variable& var : var_table)
    {
        if (var.name == s)
        {
            return var.value;
        }
    }
    error("get: undefined variable ", s);
    return 0.0;
}

void set_value(string s, double d)
{
    for (Variable& var : var_table)
    {
        var.value = d;
        return;
    }
    error("set: undefined variable ", s);
}

bool is_declared(string var)
{
    for (const Variable& v : var_table)
    {
        if (v.name == var)
        {
            return true;
        }
    }
    return false;
}

double define_name(string var, double val)
{
    if (is_declared(var))
    {
        error(var, " declared twice");
    }
    var_table.push_back(Variable{var, val});
    return val;
}

/*
    assume we've seen "let"
    handle: name = expression
    declare a variable called "name" with the initial value "expression"
*/
double declaration()
{
    Token token{token_stream.get()};

    if (token.kind != name)
    {
        error("name expected in declaration");
    }
    string var_name{token.name};

    Token token2{token_stream.get()};
    if (token2.kind != '=')
    {
        error("= missing in declaration of ", var_name);
    }

    double d{expression()};
    define_name(var_name, d);
    return d;
}
