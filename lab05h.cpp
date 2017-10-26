/*
Author: Ram Moore
Class: CS1428 lab
Section: Honors 2
Lab: 05 A
*/
#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    double check = -1.0;
    double tipPercent = -1.0;
    double tipTotal = 0.0;

    while (check < 0.0){
        cout << "Enter the check subtotal: ";
        cin >> check;
    }

    while (tipPercent > 100 || tipPercent < 0){
        cout << "Enter the percent you would like to calculate: ";
        cin >> tipPercent;
    }

    tipPercent *= 0.01;

    tipTotal = tipPercent * check;

    cout << "Your tip is " << tipTotal << " and your check total is " << tipTotal+check;

    return 0;
}
