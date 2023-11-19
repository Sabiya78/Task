#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;
int main() {
    srand(time(0));
    int randomNumber = rand() % 100 + 1;
    int userGuess;
    int attempts = 0;

    cout << "Welcome to the Number Guessing Game!\n";
    cout << "Try to guess the random number between 1 and 100.\n\n";
    do {
        cout << "Enter your guess: ";
        cin >> userGuess;
        attempts++;
        if (userGuess > randomNumber) {
            cout << "Too high! Try again.\n";
        } else if (userGuess < randomNumber) {
            cout << "Too low! Try again.\n";
        } else {
            cout << "\nCongratulations! You guessed the correct number in "
                      << attempts << " attempts.\n";
        }

    } while (userGuess != randomNumber);

    return 0;
}
