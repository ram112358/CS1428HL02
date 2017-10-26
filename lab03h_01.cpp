/*
Author: Ram Moore
Class: CS1428 lab
Section: Honors 2
Lab: 03_02
*/
#include<iostream>

using namespace std;

int main(){
    int base = 0;
    int power = 0;
    int result = 1;

    cout << "Enter your base number: ";
    cin >> base;

    cout << "Enter your power: ";
    cin >> power;

    for (int i = 0; i < power; i++)
        result *= base;

    cout << "The answer is: " << result;

    return 0;
}
