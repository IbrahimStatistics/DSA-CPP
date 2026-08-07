// Seperating Numbers

/*
5 is 12345 % 10
4 is 12345 / 10 % 10
3 is 12345 / 100 % 10
2 is 12345 / 1000 % 10
1 is 12345 / 10000 % 10
*/

#include<iostream>
#include<vector>
using namespace std;

void original(vector<int> reverse)
{
    int start = 0, end = (reverse.size()-1)/2;
    int mid = (start+end)/2;
    for(int i = 0;; i++)
}

int main(){
    vector<int> reverse;
    int n = 12345;

    for(int i = 1; (n/i)>0; i*=10)
    {
        reverse.push_back((n/i)%10);
    }

    for(int i : reverse)
    {
        cout << i << endl;
    }

    return 0;
}