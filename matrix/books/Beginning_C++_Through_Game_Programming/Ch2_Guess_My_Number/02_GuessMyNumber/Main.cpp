// Guess My Number
// Classic number guessing game

#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

enum difficulty
{
    EASY = 10,
    MEDIUM = 6,
    HARD = 3
};

int main()
{
    cout << "\n\nWelcome to Guess my Number\n\n";

    bool playAgain = true;
    bool guessesLeft = true;

    difficulty maxTries;

    while (playAgain)
    {
        cout << "Difficulty: " << endl;
        cout << "1 - Easy" << endl;
        cout << "2 - Medium" << endl;
        cout << "3 - Hard" << endl;

        int difficultyChosen;
        cout << "\nChoose Difficulty: ";
        cin >> difficultyChosen;

        switch (difficultyChosen)
        {
        case 1:
            maxTries = EASY;
            break;
        case 2:
            maxTries = MEDIUM;
            break;
        case 3:
            maxTries = HARD;
            break;
        default:
            maxTries = EASY;
        }

        cout << "\nMax Tries: " << maxTries << endl;

        // seed random number generator
        srand(static_cast<unsigned int>(time(0)));
        int secretNumber = rand() % 100 + 1; // 1-100
        int tries = 0;
        int guess;

        do
        {
            cout << "\nEnter your guess: ";
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

            // if (tries == maxTries)
            // {
            //     guessesLeft = false;
            // }

        } while (guess != secretNumber && guessesLeft);

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