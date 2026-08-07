// Check for prime
#include<iostream>
using namespace std;

bool isPrime(int n){
    for(int i = 2; i*i<=n; i++){
        if(n%i==0)
            return false;
    }
    
    return true;
}

int primeCount(int start, int end){
    int count = 0;
    bool primeStatus = false;
    
    for(int i = start; i<=end; i++){
        primeStatus = isPrime(i);
        if(primeStatus)
            count++;
    }
    
    return count;
}

int main(){
    int start, end;
    cout << "Start : ";
    cin >> start;
    
    cout << "End : ";
    cin >> end;
    
    int result;
    
    if(start == 1 && end == 1){
        cout << "0";
    } else {
        result = primeCount(start, end);
        cout << "Prime Numbers between " << start << " and " << end << " : " << result;
    }
    
    return 0;
}






