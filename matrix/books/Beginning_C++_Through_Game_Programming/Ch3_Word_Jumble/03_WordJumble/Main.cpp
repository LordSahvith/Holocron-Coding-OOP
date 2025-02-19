// Word Jumble
// The classic word jumble game where the player can ask for a hint

#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

using namespace std;

enum field
{
    WORD,      // 0
    HINT,      // 1
    NUM_FIELDS // 2
};

int main()
{
    const int NUM_WORDS = 5;
    const string WORDS[NUM_WORDS][NUM_FIELDS] = {{"wall", "Do you feel you're banging your head against something?"},
                                                 {"glasses", "These might help you see the answer."},
                                                 {"labored", "Going slowly, is it?"},
                                                 {"persistent", "Keep at it."},
                                                 {"jumble", "It's what the game is all about."}};

    bool keepPlaying = true;

    while (keepPlaying)
    {
        srand(static_cast<unsigned int>(time(0)));
        int choice = (rand() % NUM_WORDS);
        string theWord = WORDS[choice][WORD]; // word to guess
        string theHint = WORDS[choice][HINT]; // hint for word

        string jumbledWord = theWord;
        int length = jumbledWord.size();
        for (int i = 0; i < length; ++i)
        {
            int index1 = (rand() % length);
            int index2 = (rand() % length);
            char temp = jumbledWord[index1];
            jumbledWord[index1] = jumbledWord[index2];
            jumbledWord[index2] = temp;
        }

        cout << "\n\nWelcome to Word Jumble!\n\n";

        cout << "Unscramble the letters to make a word.\n";
        cout << "Enter 'hint' for a hint.\n";
        cout << "Enter 'quit' to quit the game.\n";
        cout << "The jumble is: " << jumbledWord << endl;

        string guess;
        cout << "\nYour guess: ";
        cin >> guess;

        while ((guess != theWord) && (guess != "quit"))
        {
            if (guess == "hint")
            {
                cout << theHint << endl;
            }
            else
            {
                cout << "Sorry, that's not it." << endl;
            }

            cout << "\nYour guess: ";
            cin >> guess;
        }

        if (guess == "quit")
        {
            keepPlaying = false;
            break;
        }

        if (guess == theWord)
        {
            cout << "\nThat's it! You guessed it!\n";

            char option;
            cout << "\nKeep playing? (y/n): ";
            cin >> option;

            if (option == 'n')
            {
                keepPlaying = false;
                break;
            }
        }
    }

    cout << "\nThanks for playing.\n";

    return 0;
}