#include <iostream>
#include <cstdlib>  // For rand() and srand()
#include <ctime>    // For time()
using namespace std;
int main() {
    // Seed random number generator using current time
    srand(static_cast<unsigned>(time(0)));
    int secret = rand() % 100 + 1; // Random number between 1–100
    int guess;
    int attempts = 0; // To count how many tries
    cout << "🎯 Welcome to the Number Guessing Game!\n";
    cout << "Guess a number between 1 and 100.\n";

    // Keep looping until the guess is correct
    while (true) {
        cout << "Enter your guess: ";
        cin >> guess;
        attempts++;
        if (guess == secret) {
            cout << "✅ Correct! You guessed it in " << attempts << " attempts.\n";
            break;
        } else if (guess > secret) {
            cout << "📉 Too high! Try a lower number.\n";
        } else {
            cout << "📈 Too low! Try a higher number.\n";
        }
    }
    return 0;
}
