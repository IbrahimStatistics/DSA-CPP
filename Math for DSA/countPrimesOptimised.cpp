// Most Optimised solution to count number of primes in a range
// Sieve of Eratosthenes

#include<iostream>
#include<vector>
using namespace std;

bool isPrime(int n){
    for(int i = 2; i*i<=n; i++){
        if(n%i==0)
            return false;
    }

    return true;
}

vector<bool> countPrimes(int n){
    vector<bool> numbers(n, true);
    numbers[0] = false;
    numbers[1] = false;

    int count = 0;
    
    for(int i = 2; i<=n; i++){
        if(isPrime(i)){
            count++;
            for(int j = 2; j<=n; j++){
                numbers[i*j] = false;
            }
        } 
    }

    return numbers;
}

int primeCount(int n){
    vector<bool> numbers(n,true);
    numbers[0] = false; numbers[1] = false;
    int count = 0;
    for(int i = 2;i<n; i++){
        if(isPrime(i)){
            count++;
            for(int j = 1; i*j<n; j++){
                numbers[i*j] = false;
            }
        } else {
            numbers[i] = false;
        }
    }

    return count;
}


int main(){
    vector<bool> result = countPrimes(10);

    for(bool i : result)
        cout << i << endl;

    cout << "Count : " << primeCount(10);

    return 0;
}

/*
   for(int i = 2; i<n;i++){
        if(isPrime(i)){
            count++;
            for(int j = i*2; j<n; j++){
                numbers[j] = false;
            }
        } else {
            numbers[i] = false;
        }
    }
*/

/*
vector<bool> countPrimes(int n){
    
    
}
*/