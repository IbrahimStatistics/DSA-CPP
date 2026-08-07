#include <iostream>
#include <vector>
using namespace std;

// Merges two sorted sub-arrays into one sorted section
void merge(int arr[], int low, int mid, int high) {
    // Calculate sizes of the two temporary sub-arrays
    int n1 = mid - low + 1;
    int n2 = high - mid;

    // Create temporary arrays
    vector<int> left(n1), right(n2);

    // Copy data to temporary arrays left[] and right[]
    for (int i = 0; i < n1; i++) left[i] = arr[low + i];
    for (int j = 0; j < n2; j++) right[j] = arr[mid + 1 + j];

    // Merge the temporary arrays back into arr[low..high]
    int i = 0; // Initial index of first sub-array
    int j = 0; // Initial index of second sub-array
    int k = low; // Initial index of merged sub-array

    while (i < n1 && j < n2) {
        if (left[i] <= right[j]) {
            arr[k] = left[i];
            i++;
        } else {
            arr[k] = right[j];
            j++;
        }
        k++;
    }

    // Copy any remaining elements of left[], if there are any
    while (i < n1) {
        arr[k] = left[i];
        i++;
        k++;
    }

    // Copy any remaining elements of right[], if there are any
    while (j < n2) {
        arr[k] = right[j];
        j++;
        k++;
    }
}

// The main recursive function that divides the array
void mergeSort(int arr[], int low, int high) {
    if (low < high) {
        int mid = low + (high - low) / 2; // Finds the middle point

        // Divide: Sort first and second halves
        mergeSort(arr, low, mid);
        mergeSort(arr, mid + 1, high);

        // Conquer: Merge the sorted halves
        merge(arr, low, mid, high);
    }
}

int main() {
    int arr[] = {8, 7, 4, 2, 9, 1, 5, 6};
    int n = sizeof(arr) / sizeof(arr[0]);

    mergeSort(arr, 0, n - 1);

    cout << "Sorted array: ";
    for (int i = 0; i < n; i++) cout << arr[i] << " ";
    cout << endl;

    return 0;
}