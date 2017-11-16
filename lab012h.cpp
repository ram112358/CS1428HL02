#include <iostream>

using namespace std;

int fibonacci(int n);
int factorial(int n);

int main(){
    int menu, n;
    cout << "Enter 1 for ! and 2 for a fibonacci boy: ";
    cin >> menu;
    cout << "Enter the number you want to compute the factorial of or thenth digit of fibonacci: ";
    cin >> n;
    menu == 1 ? cout << factorial(n) : cout << fibonacci(n);

    return 0;
}

int factorial(int n){
    //cout << n;
    return n == 1 ? n : n * factorial(n - 1);
}

int fibonacci (int n){
    return (n == 0  || n == 1) ? n : fibonacci(n - 1) + fibonacci(n -2);
}
