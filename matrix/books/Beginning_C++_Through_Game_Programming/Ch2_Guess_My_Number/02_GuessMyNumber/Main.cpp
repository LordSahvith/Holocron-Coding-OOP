// Guess My Number
// Classic number guessing game

#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main()
{
    bool playAgain = true;

    while (playAgain)
    {
        // seed random number generator
        srand(static_cast<unsigned int>(time(0)));
        int secretNumber = rand() % 100 + 1; // 1-100
        int tries = 0;
        int guess;

        cout << "\n\n\tWelcome to Guess my Number\n\n";

        do
        {
            cout << "Enter your guess: ";
            cin >> guess;
            ++tries;

            if (guess == secretNumber)
            {
                cout << "\nThat's it! You got it in " << tries << " guesses!\n";
            }

            if (guess > secretNumber)
            {
                cout << "\nToo high!\n\n";
            }

            if (guess < secretNumber)
            {
                cout << "\nToo low!\n\n";
            }

        } while (guess != secretNumber);

        char choice;
        cout << "\nNice job! Play again? (y/n): ";
        cin >> choice;

        if (choice == 'n')
        {
            playAgain = false;
        }
    }

    return 0;
}