#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

void insertionSort(vector<int>& arr) {
    for(int i = 1; i < arr.size(); i++) {
        int key = arr[i];
        int j = i - 1;

        while(j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }

        arr[j + 1] = key;
    }
}


int main() {
    vector<int> arr = {4,5,2,1,3};
    insertionSort(arr);

    for(auto &it : arr) {
        cout << it << " ";
    }

    return 0;
}