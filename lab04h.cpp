/*
Author: Ram Moore
Class: CS1428 lab
Section: Honors 2
Lab: 04
*/
#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    //Declaring constants
    const int OP_ADD = 0;
    const int OP_SUB = 1;
    const int OP_MUL = 2;
    const int OP_DIV = 3;
    const int OP_MOD = 4;
    const int OP_EXP = 5;
    const int OP_RED = 6;
    const int OP_WRT = 7;

    // declaring the programs RAM
    int RAM[256] = {4 , 23 , 10 , 40 , 5};
    int instructionCount = -1;
    int inst[32] = {0};
    int data0[32] = {0};
    int data1[32] = {0};
    int data2[32] = {0};

        //Telling the user what number coresponds to what function
    cout << "For each of the following operators enter the corresponding number: " << endl;
    cout << "Add:       0" << endl;
    cout << "Subtract:  1" << endl;
    cout << "Multiply:  2" << endl;
    cout << "Divide:    3" << endl;
    cout << "Modulus:   4" << endl;
    cout << "Exponent:  5" << endl;
    cout << "Read:      6" << endl;
    cout << "Write:     7" << endl;

    cout << "We have the array RAM[256] that currently has the values (4 , 23 , 10 , 40 , 5)." << endl;
    while (instructionCount < 0 || instructionCount > 32){
        cout << "Enter the number of instructions for your program (0 - 32): ";
        cin >> instructionCount;
    }

    for (int i = 0; i < instructionCount; i++){
        inst[i]--;
        while (inst[i] < 0 || inst[i] > 7){
            cout << "Enter the operation code: ";
            cin >> inst[i];
        }

        data0[i]--;
        while (data0[i] < 0 || data0[i] > 255){
            cout << "Enter the store index: ";
            cin >> data0[i];
        }

        data1[i]--;
        while (data1[i] < 0 || data1[i] > 255){
            cout << "Enter the first value index: ";
            cin >> data1[i];
        }

        data2[i]--;
        while (data2[i] < 0 || data2[i] > 255){
            cout << "Enter the second value index: ";
            cin >> data2[i];
        }
    }
    for (int i = 0; i < instructionCount; i++){
        switch (inst[i]){
            case OP_ADD:
                RAM[data0[i]] = RAM[data1[i]] + RAM[data2[i]];
                break;
            case OP_SUB:
                RAM[data0[i]] = RAM[data1[i]] - RAM[data2[i]];
                break;
            case OP_MUL:
                RAM[data0[i]] = RAM[data1[i]] * RAM[data2[i]];
                break;
            case OP_DIV:
                RAM[data0[i]] = RAM[data1[i]] / RAM[data2[i]];
                break;
            case OP_MOD:
                RAM[data0[i]] = RAM[data1[i]] % RAM[data2[i]];
                break;
            case OP_EXP:
                RAM[data0[i]] = pow(RAM[data1[1]] , RAM[data2[i]]);
                break;
            case OP_RED:
                cout << "Enter the value you want to store at the index " << data0[i];
                cin >> RAM[data0[i]];
                break;
            case OP_WRT:
                cout << "The value at " << data0[i] << " is " << RAM[data0[i]] << endl;
                break;
            default:
                cout << endl << "Unable to perform operation #" << i + 1;
                break;
            }
    }

    return 0;
}
