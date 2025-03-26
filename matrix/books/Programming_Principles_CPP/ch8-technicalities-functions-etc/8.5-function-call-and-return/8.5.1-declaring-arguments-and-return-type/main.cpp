#include "../../../00_std_lib_facilities.h"

double fct(int a, double d);                        // declaration of fct (no body)
int current_power();                                // doesn't take an argument
void increase_power_to(int level);                  // doesn't return value
int my_find(vector<string> vs, string s, int hint); // naming arguments
int my_find(vector<string>, string, int);           // not naming arguments

int main()
{
}

double fct(int a, double d) // definition of fct
{
    return a * d;
}

int my_find(vector<string> vs, string s, int)
{
    for (size_t i = 0; i < vs.size(); i++)
    {
        if (vs[i] == s)
        {
            return i;
        }
    }
    return -1;
}