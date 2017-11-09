//asdfg

#include <iostream>
#include <cmath>

using namespace std;

bool isPrime(int num);
bool isHappy(int num);
bool addToCycle(int num);
bool cycleContains(int num);
void selectionSort();
int happify(int num);

int cycle[256];

int main(){
    int num = 0;
    while (true){
        cout << "Enter the number you wish to check: ";
        cin >> num;
        if (num == 0){
            break;
        }
        (isPrime(num) && isHappy(num)) ? cout << "https://youtu.be/y6Sxv-sUYtM" << endl : cout << "sad number" << endl;
    }
    return 0;
}

bool isPrime(int num){
    for (int i = 2; i <= sqrt(num); i++){
        if (num % i == 0){
            return false;
        }
    }
    return true;
}

bool addToCycle(int num){
    int i;
    if (cycleContains(num)){
        return false;
    }
    for (i = 0; cycle[i] != 0; i++){}
    cycle[i] = num;
    selectionSort();
    return true;
}

bool cycleContains(int num){
    for (int i = 0; i < 255; i++){
        if (cycle[i] == num){
            return true;
        }
        if (cycle[i] == 0){
            return false;
        }
    }
    return false;
}

void selectionSort(){
    int minIndex;
    int minValue;
    for (int beginning = 0; beginning < 255; beginning++){
        minIndex = beginning;
        minValue = cycle[beginning];
        for (int i = beginning + 1; i < 255; i++){
            if (cycle[i] < minValue){
                minValue = cycle[i];
                minIndex = i;
            }
        }
        cycle[minIndex] = cycle[beginning];
        cycle[beginning] = minValue;
    }
}

int happify(int num){
    int newNum = 0;
    while (num > 0){
        newNum += (num % 10) * (num % 10);
        num /= 10;
    }
    return newNum;
}

bool isHappy(int num){
    if (!addToCycle(num) || num == 1){
        return true;
    }
    return isHappy(happify(num));
}
