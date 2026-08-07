#include<iostream>
using namespace std;

int main() {
    int freq = 0;
    int max;
    cout << "Members per group: ";
    cin >> max;
    
    int j = 1; 
    int temp = 0;

    cout << "Group 1: -" << endl;
    for(int i = 67; i<= 143; i++) {
        if(i == 85 || i == 88 || i == 107 || i == 113) continue;

        if(i <= 132) {
            cout << i << endl;
        } else {
            int k;
            k = 501 + temp;
            temp = i - 132;

            cout << k << endl;
        }

        freq++;
        
        if(freq == max) {
            freq = 0;
            cout << "==========" << endl;
            cout << "Group " << ++j << ": -" << endl;
        }
    }
    
    
    return 0;
}