#include <iostream>
#include <string>

using namespace std;

int main()
{
    string PyramidString{};

    cout << "Enter a string: ";
    cin >> PyramidString;

    /*
        get the halfway point of pyramid's full length

        Ex.
            String: abc
            Length: 3
            Formula: string + (string - 1)
                        3   + (  3    - 1) = 5 / 2 (int conversion so .5 is cutoff)
            RowHalfwayMarker: 2;
    */
    size_t RowHalfwayMarker{PyramidString.length() + (PyramidString.length() - 1) / 2};

    for (size_t Row{0}; Row < PyramidString.length(); Row++)
    {
        /*
            Add Whitespaces to match the row count.

            Formula: HalfwayMarker - Row = Spaces

            Ex. Row = 0
                Halfway Marker = 2

                Loops:
                    1. 2 - 0 = 2
                    2. 2 - 1 = 1
                    3. 2 - 2 = 0
        */
        for (size_t Column{Row}; Column < RowHalfwayMarker; Column++)
        {
            cout << " ";
        }

        /*
            Print First Half of Characters to match the row count.

            Formula: Row + 1 = Number of Characters to print

            Ex. Row = 0

                Loops:
                    1. Prints 1 Character = 0 + 1
                    1. Prints 2 Character = 1 + 1
                    1. Prints 3 Character = 2 + 1
        */
        for (size_t Column{0}; Column <= Row; Column++)
        {
            cout << PyramidString.at(Column);
        }

        /*
            Print Second Half of Characters in reverse starting with
            the last character in the string - 1 (aka, if it was b,
            then a would print, or if it's c, then b would print,
            followed by a)

            Formula: Row - (Column + 1) = PyramidString.at(Last - 1)

            ** Note: Starting at Row 1 since the First Loop doesn't
                require anymore printed characters.

            Ex. Row = 1
                Column = 0

                currently printed on screen:
                  a
                 ab

                and we need to find the next in line or 'a', so using
                the above formula we get:
                    1 - (0 + 1) = 0
                or 'a'

                  a
                 aba

                then:
                  a
                 aba
                abc

                next we find the remaining two characters:
                    2 - (0 + 1) = 1 : 'b'

                giving:
                  a
                 aba
                abcb

                then the final:
                    2 - (1 + 1) = 0 : 'a'

                finalizing:
                  a
                 aba
                abcba
        */
        for (size_t Column{0}; Column < Row; Column++)
        {
            size_t index = Row - (Column + 1);
            cout << PyramidString.at(index);
        }

        cout << endl;
    }

    return 0;
}