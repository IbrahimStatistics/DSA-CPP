#include<iostream>
using namespace std;

void selectionSort(int arr[], int n) {
    for(int i = 0; i<=n-2; i++) {
        int minIdx = i;
        for(int j = i; j<=n-1; j++) {
            if(arr[j]<arr[minIdx]) {
                minIdx = j;
            }

            swap(arr[i], arr[minIdx]);
        }
    }
}

int main() {
    int arr[] = {13,46,24,52,20,9};
    int n = sizeof(arr)/sizeof(int);

    cout << "Before Sorting: ";
    for(int i = 0; i<n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
    selectionSort(arr, n);
    
    cout << "After Sorting: ";
    for(int i = 0; i<n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}