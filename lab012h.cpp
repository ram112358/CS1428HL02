#include <iostream>

using namespace std;

int fibonacci(int n);
int factorial(int n);

int main(){
    int n;
    cout << "Enter the number: ";
    cin >> n;
    cout << "Factorial of "<< n << ": "<< factorial(n);
    cout << n <<"th fibonaci number: " << fibonacci(n);
    return 0;
}

int factorial(int n){
    return n == 1 ? n : n * factorial(n - 1);
}

int fibonacci (int n){
    return (n == 0  || n == 1) ? n : fibonacci(n - 1) + fibonacci(n -2);
}
