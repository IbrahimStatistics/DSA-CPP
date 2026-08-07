/*
    GCD/HCF
*/

#include<iostream>
#include<algorithm>
using namespace std;

int bruteForcefindGCD(int a, int b){
    int limit = min(a,b);
    int gcd;
    
    for(int i = 1; i<=limit; i++){
        if(a%i==0 && b%i==0){
            gcd = i;
        }
    }
    
    return gcd;
}

int euclidean(int a, int b){
    while(a>0 && b>0){
        if(a>b)
            a = a%b;
        else
            b = b%a;
    }

    if(a==0) return b;
    if(b==0) return a;
}

int main(){
    int a = 54, b = 98;
    
    cout << "GCD : " << euclidean(a,b);
    
    return 0;
}