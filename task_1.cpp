#include <iostream>
#include <cstdlib> // Changed from stdlib.h to cstdlib
#include <ctime>
using namespace std;

int main() {
    cout << "===========================================================================================================================" << endl;
    cout << "=================================================== Number Guessing Game ====================================================" << endl;
    cout << "===========================================================================================================================" << endl << endl;

    srand(static_cast<unsigned int>(time(0))); // Seed for random number generation

    int targetNumber; // Variable to hold the random number to guess
    int difficultyLevel; // Variable to store the difficulty level

    cout << "Select difficulty level: 1 for Easy, 2 for Normal, 3 for Hard, or any other key to exit." << endl;
    cin >> difficultyLevel;

    while (difficultyLevel == 1 || difficultyLevel == 2 || difficultyLevel == 3) {
        if (difficultyLevel == 1) {
            targetNumber = rand() % 10 + 1; // Random number between 1 and 10
            cout << "You've selected Easy mode. Guess a number between 1 and 10." << endl;
        } 
        else if (difficultyLevel == 2) {
            targetNumber = rand() % 100 + 1; // Random number between 1 and 100
            cout << "You've selected Normal mode. Guess a number between 1 and 100." << endl;
        } 
        else {
            targetNumber = rand() % 1000 + 1; // Random number between 1 and 1000
            cout << "You've selected Hard mode. Guess a number between 1 and 1000." << endl;
        }

        int playerGuess; // Variable for the user's guess
        cout << "Enter your guess: ";
        cin >> playerGuess;

        while (playerGuess != targetNumber) {
            if (playerGuess < targetNumber) {
                cout << "Your guess is too low. Try again!" << endl;
            } 
            else {
                cout << "Your guess is too high. Try again!" << endl;
            }
            cout << "Enter your guess: ";
            cin >> playerGuess;
        }

        cout << "Congratulations! You've guessed the number: " << targetNumber << endl;

        cout << "Select difficulty level: 1 for Easy, 2 for Normal, 3 for Hard, or any other key to exit." << endl;
        cin >> difficultyLevel;
    }

    cout << "Thank you for playing!" << endl; // Ending message before exit
    return 0;
}
