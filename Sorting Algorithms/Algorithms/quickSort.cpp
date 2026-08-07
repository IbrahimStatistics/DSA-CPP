#include<iostream>
using namespace std;

int parition(int arr[], int low, int high) {
    int pi = high;
    int i = low-1;
    for(int j = low; j<=high; j++) {
        if(arr[j]<arr[pi]) {
            i++;
            swap(arr[i], arr[j]);
        }
    }

    swap(arr[i+1], arr[pi]);
    return i+1;
}

void quickSort(int arr[], int low, int high) {
    if(low < high) {
        int pi = parition(arr, low, high);

        quickSort(arr, low, pi-1);
        quickSort(arr, pi+1, high);
    }
}

int main() {
    int arr[] = {10,80,30,90,40,50};
    int size = sizeof(arr)/sizeof(int);

    cout << "Before Sorting: ";
    for(int i  = 0; i<size; i++) cout << arr[i] << " ";
    cout << endl;
    
    quickSort(arr, 0, size-1);
    
    cout << "Before Sorting: ";
    for(int i  = 0; i<size; i++) cout << arr[i] << " ";
    cout << endl;

    return 0;
}