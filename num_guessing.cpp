#include <iostream>
using namespace std;

int main() {
    int secret_num = 7;
    int lives = 3;
    int guess = 0;
    while (guess != secret_num && lives != 0) {
        cout << "Enter your guess: ";
        cin >> guess;
        --lives;
    }
    if (lives == 0) { cout << "You lost!"; } else { cout << "You won!"; }
    return 0;
}