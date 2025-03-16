#include "../../../00_std_lib_facilities.h"

int main()
{
    int maxNum{100};
    int currentGuess{50};
    int lastGuess{0};
    int lowestGuess{currentGuess};
    int highestGuess{currentGuess};

    char playerResponse;

    cout << "Pick a number between 1 and " << maxNum << "...hit enter when ready: ";
    cin >> playerResponse;

    bool guessedCorrectly{false};
    while (!guessedCorrectly)
    {
        cout << "Is the number less than " << currentGuess << "? (l/g/e): " << endl;
        cin >> playerResponse;

        // figure out new guess
        int newGuess{0};
        if (currentGuess > lastGuess)
        {
            newGuess = (currentGuess - lastGuess) / 2;
            highestGuess = currentGuess;
        }
        else if (currentGuess < lastGuess)
        {
            newGuess = (lastGuess - currentGuess) / 2;

            if (newGuess <= 0)
            {
                newGuess = 1;
            }

            lowestGuess = currentGuess;
        }
        else
        {
            newGuess = (highestGuess - lowestGuess) / 2;
        }

        // check if guessed number is greater/less than secret number
        if (toupper(playerResponse) == 'L')
        {
            lastGuess = currentGuess;
            currentGuess -= newGuess;
        }
        else if (toupper(playerResponse) == 'G')
        {
            lastGuess = currentGuess;
            currentGuess += newGuess;
        }
        else if (toupper(playerResponse) == 'E')
        {
            cout << "The answer is: " << currentGuess << endl;
            guessedCorrectly = true;
        }
    }
}