#include<iostream>
using namespace std;

int main(){
    // print the fibonacci series up to n terms
    // 0,1,1,2,3,5,8,13,..
    int n ;
    int a = 0, b = 1;
    int next = a + b;
    
    cout << "Enter n : ";
    cin >> n;

    if(n==1) cout << 0;
    if(n==2) cout << 0 << " " << 1;
    
    if(n>=3){
        cout << a << " " << b;
        int i = 1;
        while(i<=n-2){
            a = b;
            b = next;
            next = a+b;
            cout << " " << next;
            i++;
        }
    }


    return 0;
}