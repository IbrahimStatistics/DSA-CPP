/*
SEPERATE DIGITS IN A NUMBER.
*/

#include<iostream>
#include<vector>
using namespace std;

int main(){
    vector<int> sepNum;
    int num;
    cout << "Enter num : ";
    cin >> num;

    if(num==0) sepNum.push_back(0);
    else if(num<0) num = -num;

    while(num>0){
        int digit = num%10;
        sepNum.push_back(digit);
        num/=10;
    }

    for(auto it = sepNum.rbegin(); it != sepNum.rend(); ++it){
        cout << *it << " ";
    }

    return 0;

    /*
    SHORT CUT TO FIND OUT THE NUMBER OF DIGITS IN A NUMBER (Use log)
    ~   cout << log10(n)+1 ;
    */

}