#include <iostream>
using namespace std;

class guessNumber {
    int num, opt, numList[10], userGuess, menuOpt, istrue, attempts;

public:
    guessNumber() {
        cout << "Welcome to the number guessing game." << endl
             << "ALL CREDITS OF THIS GAME GO TO \"ABHI SHAH\"" << endl << endl;

        numList[0] = 52;
        numList[1] = 45;
        numList[2] = 88;
        numList[3] = 34;
        numList[4] = 99;
        numList[5] = 78;
        numList[6] = 77;
        numList[7] = 12;
        numList[8] = 96;
        numList[9] = 54;
    }

    void menu() {
        cout << "Select the game options:" << endl;
        cout << "1. Start Game With PreDefined Numbers" << endl;
        cout << "2. Enter Custom Number List" << endl;
        cout << "3. Refresh Current Numbers" << endl;
        cout << "4. Super Refresh Numbers (Can Go to 1000+ too)" << endl;
        cout << "5. Exit" << endl;
        cin >> menuOpt;

        switch (menuOpt) {
            case 1:
                actualNumber();
                guessingStart();
                break;
            case 2:
                customInput();
                actualNumber();
                guessingStart();
                break;
            case 3:
                refreshNumbers();
                actualNumber();
                guessingStart();
                break;
            case 4:
                superRefresh();
                actualNumber();
                guessingStart();
                break;
            case 5:
                cout << "Thanks for playing!" << endl;
                exit(0);
            default:
                cout << "INVALID CHOICE!!" << endl;
        }
    }

    void refreshNumbers() {
        numList[0] += 45;
        numList[1] += 12;
        numList[2] += 88;
        numList[3] += 31;
        numList[4] += 2;
        numList[5] += 54;
        numList[6] += 42;
        numList[7] += 32;
        numList[8] += 78;
        numList[9] += 65;
    }

    void superRefresh() {
        numList[0] += 845;
        numList[1] -= 252;
        numList[2] += 688;
        numList[3] -= 25;
        numList[4] += 52;
        numList[5] -= 34;
        numList[6] += 482;
        numList[7] -= 22;
        numList[8] += 758;
        numList[9] += 565;
    }

    void customInput() {
        cout << "Enter 10 custom numbers (they will be shuffled):" << endl;
        for (int i = 0; i < 10; i++) {
            cout << "Enter number " << i + 1 << ": ";
            cin >> numList[i];
        }

        int temp;
        temp = numList[0];
        numList[0] = numList[4];
        numList[4] = temp;

        temp = numList[1];
        numList[1] = numList[8];
        numList[8] = temp;

        temp = numList[2];
        numList[2] = numList[6];
        numList[6] = temp;

        temp = numList[3];
        numList[3] = numList[9];
        numList[9] = temp;

        temp = numList[5];
        numList[5] = numList[7];
        numList[7] = temp;
    }

    void actualNumber() {
        cout << "Enter the number of characters in your name OR choose a number between 1-10: ";
        cin >> opt;
        if (opt >= 1 && opt <= 10)
            num = numList[opt - 1];
        else {
            cout << "Invalid option, choosing default." << endl;
            num = numList[0];
        }
    }

    void guessingStart() {
        istrue = 1;
        attempts = 0;
        cout << "Now guess the number:" << endl;

        while (istrue == 1) {
            cout << "Enter your guess: ";
            cin >> userGuess;
            attempts++;

            if (userGuess == num) {
                cout << "\n \n\"You guessed the number right :)\"  Congratulations!!" << endl;
                cout << "You took " << attempts << " attempts.\n" << endl;
                istrue = 0;
            } else if (userGuess >= num + 50) {
                cout << "\"You have gone too far.\"  Come back to smaller numbers." << endl;
            } else if (userGuess <= num - 50) {
                cout << "\"You have gone too far.\"  Come back to larger numbers." << endl;
            } else if (userGuess > num) {
                cout << "\"You are really close :)\"  Try going down!" << endl;
            } else if (userGuess < num) {
                cout << "\"You are really close :)\"  Try going up!" << endl;
            } else {
                cout << "\"Invalid input.\" Try again." << endl;
            }
        }
    }
};

int main() {
    guessNumber g;
    while (true) {
        g.menu();
    }
    return 0;
}
