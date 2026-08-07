/*
LCM Formula = a*b / gcd(a,b);
*/

#include<iostream>
#include<vector>
using namespace std;

int GCD(int a, int b){
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

    cout << "LCM of " << a << " and " << b << " : " << GCD(a,b);

    return 0;
}