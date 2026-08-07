// Heap Sort
#include<iostream>
#include<vector>
using namespace std;

void heapify(vector<int> &arr, int n, int index) {
    int largest = index;
    
    int left = 2 * index + 1;
    int right = 2 * index + 2;
    
    if(left < n && arr[left] > arr[largest]) {
        largest = left;
    }
     if(right < n && arr[right] > arr[largest]) {
         largest = right;
     }
     
     if(largest != index) {
        swap(arr[largest], arr[index]);
        heapify(arr, n, largest);
     }
}

void heapSort(vector<int> &arr) {
    int n = arr.size();
    
    for(int i = n/2-1; i>=0; i--) {
        heapify(arr, n, i);
    }
    
    for(int i = n-1; i>=0; i--) {
        swap(arr[0], arr[i]);
        heapify(arr, i, 0);
    }
}

int main() {
    vector<int> arr = {4,10,3,5,1};
    
    heapSort(arr);
    
    for(int i : arr) cout << i << " ";
    cout << endl;
    
    return 0;
}