// Check if given array is sorted
#include<iostream>
#include<vector>
using namespace std;

bool isSorted(vector<int> arr, int n){
    if(n==0) return true;

    if(arr[n]<arr[n-1]) return false;
    else                return (isSorted(arr,n-1));
}

int main(){
    // vector<int> arr = {1,1,4,3,1000,1000};
    vector<int> arr = {5,10,14,2,20,22};
    int n = arr.size()-1;

    cout << isSorted(arr, n);

    return 0;
}