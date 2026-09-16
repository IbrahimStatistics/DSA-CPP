#include <iostream>
#include <vector>
#include <chrono> // For high-precision timing

using namespace std;

// 1. Standard Recursion: O(2^n) time complexity
long long fib(int n) {
    if (n <= 1) return n; // Unified base case
    return fib(n-1) + fib(n-2);
}

// 2. Dynamic Programming (Memoization): O(n) time complexity
long long fibDP(int n, vector<long long>& f) {
    if (n <= 1) return n; // Unified base case

    if (f[n] != -1) {
        return f[n];
    }

    return f[n] = fibDP(n-1, f) + fibDP(n-2, f);
}

int main() {
    // n = 40 is a perfect sweet spot to show the massive performance gap
    int n = 100; 
    
    cout << "--- Benchmarking Fibonacci for n = " << n << " ---\n\n";

    // ==========================================
    // 1. Measuring Dynamic Programming (Memoization)
    // ==========================================
    vector<long long> f(n + 1, -1);
    
    auto startDP = chrono::high_resolution_clock::now();
    long long resultDP = fibDP(n, f);
    auto endDP = chrono::high_resolution_clock::now();
    
    auto durationDP = chrono::duration_cast<chrono::microseconds>(endDP - startDP);
    
    cout << "[DP Approach]\n";
    cout << "Result: " << resultDP << "\n";
    cout << "Time taken: " << durationDP.count() << " microseconds\n\n";

    // ==========================================
    // 2. Measuring Standard Recursion
    // ==========================================
    auto startRec = chrono::high_resolution_clock::now();
    long long resultRec = fib(n);
    auto endRec = chrono::high_resolution_clock::now();
    
    auto durationRec = chrono::duration_cast<chrono::microseconds>(endRec - startRec);
    
    cout << "[Standard Recursion Approach]\n";
    cout << "Result: " << resultRec << "\n";
    cout << "Time taken: " << durationRec.count() << " microseconds\n\n";

    // ==========================================
    // Comparison Summary
    // ==========================================
    double ratio = (double)durationRec.count() / (durationDP.count() > 0 ? durationDP.count() : 1);
    cout << "Summary: DP was roughly " << ratio << " times faster than plain recursion!\n";

    return 0;
}