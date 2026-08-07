// Fibonacci using recursion
#include<iostream>
using namespace std;

int printFibonacci(int n){
    if(n==0||n==1) return n;

    return (printFibonacci(n-1)+printFibonacci(n-2));
}

int fib(int n){
    if(n==0||n==1) return n;

    for(int i = 2; i<=n; i++){
        
    }
}

int main(){

    cout << printFibonacci(10);

    return 0;
}