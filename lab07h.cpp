/*
Author: Ram Moore
Class: CS1428 lab
Section: Honors 2
Lab: 07
*/
#include <iostream>
#include <iomanip>
#include <fstream>
#include <cmath>

using namespace std;

int main()
{
    // creating the fstream object for the file
    fstream file;

    //opening the file
    file.open("assembly.txt");

    // error message for the file
    if (!file){
		cout << "Failed to open the input file!" << endl;
		return -1;
    }

    //Declaring constants
    const int OP_ADD = 0;
    const int OP_SUB = 1;
    const int OP_MUL = 2;
    const int OP_DIV = 3;
    const int OP_MOD = 4;
    const int OP_EXP = 5;

    // declaring the programs RAM
    int RAM[256] = {4 , 23 , 10 , 5};
    int instructionCount = -1;
    int inst[32] = {0};
    int data0[32] = {0};
    int data1[32] = {0};
    int data2[32] = {0};

    cout << "The RAM contains: [";
    for (int i = 0; i < 256; i++){
        if (i % 16 == 0)
            cout << endl;
        cout << setw(4) << RAM[i] << ", ";
    }
    cout << "]" << endl << endl << endl;

    file >> instructionCount;

    for (int i = 0; i < instructionCount; i++){
        file >> inst[i];
        file >> data0[i];
        file >> data1[i];
        file >> data2[i];
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
                RAM[data0[i]] = pow(RAM[data1[i]] , RAM[data2[i]]);
                break;
            default:
                cout << endl << "Unable to perform operation #" << i + 1;
                break;
            }
    }

    cout << "After instructions the RAM now contains: [";
    for (int i = 0; i < 256; i++){
        if (i % 16 == 0)
            cout << endl;
        cout << setw(4) << RAM[i] << ", ";
    }
    cout << "]" << endl;

    file >> instructionCount;

    return 0;
}
