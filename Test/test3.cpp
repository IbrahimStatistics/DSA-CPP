#include<iostream>
using namespace std;

int main(){
    int n = 5;
    int count = 0;
    int sum = 0;
    
    int i = 1;
    while(count!=n){
        if(i%2==0){
            continue;
        }
        else{
            sum+=i;
            count++;
        }
        
        i++;
    }
    
    cout << sum;
    
}