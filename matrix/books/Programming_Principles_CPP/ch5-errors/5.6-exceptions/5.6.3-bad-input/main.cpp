#include "../../../00_std_lib_facilities.h"

double some_function()
{
    double d{0.0};
    cin >> d;
    if (!cin)
        error("Couldn't read a double in 'some_function()'");
    return d;
}

int main()
{
    try
    {
        double someDouble{some_function()};
        cout << "double: " << someDouble << endl;
        return 0;
    }
    catch (runtime_error& e)
    {
        std::cerr << "run-time error: " << e.what() << endl;
        return 1;
    }
}