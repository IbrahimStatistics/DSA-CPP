/*
ARMSTRONG NUMBER - An **Armstrong number** is a number equal to the sum of its own digits each raised to the power of the number of digits.
Ex - 153,371,1
*/

#include<iostream>
#include<cmath>
using namespace std;

bool checkArmstrong(int n){
    // first seperate the digits from the number
    int cpyN = n;
    int sum = 0;
    int count = log10(n)+1;

    while(n>0){
        int digit = n%10;
        sum += pow(digit,count);
        n/=10;
    }

    return sum==cpyN;
}

int main(){
    int n;
    cout << "Enter n : ";
    cin >> n;

    bool result = checkArmstrong(n);
    if(result){
        cout << n << " is an armstrong number.";
    } else {
        cout << n << " is not an armstrong number.";
    }

    return 0;
}