/*
Author: Ram Moore
Class: CS1428 lab
Section: Honors 2
Lab: 03_02
*/
#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;

int main(){
    int rangeLow;
    int rangeHigh;
    int mystery;
    int guess = -1;
    int guessCounter = 0;
    int again;
    srand(time(NULL));

    while (true){

        cout << "Enter the lower limit of your guessing range: ";
        cin >> rangeLow;

        cout << "Enter the upper limit of your guessing range: ";
        cin >> rangeHigh;

        mystery = rand();
        mystery = mystery % (rangeHigh - rangeLow + 1);
        mystery = mystery + rangeLow;
        
        while (guess != mystery){
            cout << endl << endl << "Enter your guess or -1 to quit: ";
            cin >> guess;

            guessCounter++;

            if (guess == -1){
                break;
            }
            else if (guess > rangeHigh || guess < rangeLow){
                cout << "Your guess was out of range :(";
            }
            else if (guess == mystery){
                cout << "You got it!" << endl << "It took " << guessCounter << " guesses.";
            }
            else if (guess < mystery){
                cout << "Too low :( try again";
            }
            else if (guess > mystery){
                cout << "Too high :( try again";
            }
        }

        cout << "Enter 0 to quit or 1 to continue: ";
        cin >> again;

        if (again == 0){
            break;
        }
    }
    return 0;
}
