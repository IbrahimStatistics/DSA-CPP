#include<iostream>
using namespace std;

void bubbleSort(int arr[], int n) {
    for(int i = 0; i<n-1; i++) {
        for(int j = 0; j<n-1-i; j++) {
            if(arr[j]>arr[j+1]) {
                swap(arr[j], arr[j+1]);
            }
        }
    }
}

int main() {
    int arr[] = {13, 46, 24, 52, 20, 9};
    int n = sizeof(arr)/sizeof(int);

    cout << "Before Sorting: ";
    for(int i = 0; i<n; i++) cout << arr[i] << " ";
    cout << endl;
    
    bubbleSort(arr, n);
    
    cout << "After Sorting:  ";
    for(int i = 0; i<n; i++) cout << arr[i] << " ";
    cout << endl;
    
    return 0;
}