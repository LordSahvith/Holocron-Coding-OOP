#include "Chrono.h"

using namespace Chrono;

int main()
{
    Date newDate{2025, Month::feb, 26};

    Date dayOfWeek = next_Sunday(newDate);

    return 0;
}