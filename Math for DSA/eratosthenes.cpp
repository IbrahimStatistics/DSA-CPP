// Implemenet Sieve of eratosthenes algorithm

#include<iostream>  
#include<vector>
using namespace std;

// vector<bool> result(vector<int> numbers);

bool isPrime(int n);
int countPrimes(int n);

bool isPrime(int n){
    for(int i = 2; i*i<=n; i++){
        if(n%i==0){
            return false;
        }
    }

    return true;
}

int countPrimes(int n){
    vector<bool> numbers(n, true);
    numbers[0] = numbers[1] = false;
    int count = 0;

    for(int i = 2; i<n; i++){
        if(isPrime(i)){
            count++;
            for(int j = i*2; j<n; j+=i){
                numbers[j] = false;
            }
        } 
    }

    return count;
}

int main(){
    int n;
    cout << "n : ";
    cin >> n;

    cout << countPrimes(n) << endl;
    
    return 0;
}