#include<iostream>
#include<vector>
using namespace std;

// Fibonacci Recursion Code
int fib(int n) {
    if(n <= 1) return 1;

    return fib(n-1) + fib(n-2);
}

// Fibonacci DP Code
int fibDP(int n, vector<int>& f) {
    if(n <= 1) return n;

    if(f[n] != -1) {
        return f[n];
    }

    return f[n] = fibDP(n-1, f) + fibDP(n-2, f);
}

int main() {
    cout << endl;
    int n = 60000;
    vector<int> f(n+1, -1);
    
    cout << n << "! =" << fibDP(n, f) << endl;
    
    cout << endl;
    return 0;
}