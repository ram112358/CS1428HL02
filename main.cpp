#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;

void betFunc(int &myMoney, int &bet);
void getRolls(int &compDie, int &userDie);
void results(int compDie , int userDie , int &myMoney , int bet);

int main()
{
    srand(time(NULL));
    int myMoney = 1000,
        bet = 0,
        userDie = -1,
        compDie = -1;
    char response[3];
    bool cont;

    cout << "Gambling is an addiction..." << endl;
    do {
        cout << endl;
        betFunc(myMoney , bet);
        getRolls(compDie, userDie);
        results(compDie, userDie, myMoney, bet);
        if (myMoney == 0)
            break;

        cout << "Would you like to continue? (y/n)";
        cin >> response;
        if (response[0] != 'y')
            cont = false;
    }
    while (cont && myMoney != 0);
    if (cont){
        cout << "You ran out of money :(" << endl;
    }
    cout << "You end with $" << myMoney << endl;
}

void betFunc(int &myMoney, int &bet){
    cout << "You currently have $" << myMoney << endl;
    cout << "How much do you bet?" << endl;
    cin >> bet;
    while (bet > myMoney || bet < 0){
        cout << "You can only bet amounts between 0 and " << myMoney << " try again" << endl;
        cin >> bet;
    }
}

void getRolls(int &compDie, int &userDie){
    compDie = rand() % 6 + 1;
    userDie = rand() % 6 + 1;
}

void results(int compDie , int userDie , int &myMoney , int bet){
    cout << "You rolled a " << userDie << endl;
    cout << "Your opponent rolled a " << compDie << endl;
    if (userDie < compDie){
        cout << "You loose $" << bet << endl;
        myMoney -= bet;
    }
    else if (userDie > compDie){
        cout << "You win $" << bet << endl;
        myMoney += bet;
    }
    else {
        cout << "There was a tie" << endl;
    }
}
