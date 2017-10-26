/*
Author: Ram Moore
Class: CS1428 lab
Section: Honors 2
Lab: 03_02
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

    //Declating variables
    int inst, data0, data1, data2;

    //Telling the user what number coresponds to what function
    cout << "For each of the following operators enter the corresponding number: " << endl;
    cout << "Add:  0" << endl;
    cout << "Subtract:  1" << endl;
    cout << "Multiply:  2" << endl;
    cout << "Divide: 3" << endl;
    cout << "Modulus: 4" << endl;
    cout << "Exponent: 5" << endl;

    //Starting the infinit loop
    while (true) {

        //Retrieving the first number/value
        cout << endl << "Enter your first value: ";
        cin >> data1;

        //Retrieving the second number/value
        cout << endl << "Enter your second value: ";
        cin >> data2;

        //Retrieving the operation
        cout << endl << "Enter the operation you wish to perform or enter -1 to exit: ";
        cin >> inst;
        switch (inst){
            case -1:
                return 0;
                break;
            case OP_ADD:
                data0 = data1 + data2;
                break;
            case OP_SUB:
                data0 = data1 - data2;
                break;
            case OP_MUL:
                data0 = data1 * data2;
                break;
            case OP_DIV:
                data0 = data1 / data2;
                break;
            case OP_MOD:
                data0 = data1 % data2;
                break;
            case OP_EXP:
                data0 = pow(data1 , data2);
                break;
            default:
                data0 = -1;
                cout << endl << "Unable to perform operation";
                break;
            }


        cout << endl << "The result of the operation is: " << data0;
    }
    return 0;
}
