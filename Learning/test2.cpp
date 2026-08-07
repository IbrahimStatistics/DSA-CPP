#include <iostream>
using namespace std;

void findFrequency(int arr[], int size) {
    // Array to keep track of visited elements
    bool visited[size];
    for (int i = 0; i < size; i++) {
        visited[i] = false; // Initialize all elements as not visited
    }

    // Iterate through the array
    for (int i = 0; i < size; i++) {
        // Skip if the element is already visited
        if (visited[i]) {
            continue;
        }

        // Count the frequency of the current element
        int count = 1;
        for (int j = i + 1; j < size; j++) {
            if (arr[i] == arr[j]) {
                count++;
                visited[j] = true; // Mark the duplicate as visited
            }
        }

        // Print the frequency of the current element
        cout << "Element " << arr[i] << " occurs " << count << " times." << endl;
    }
}

int main() {
    // Example array
    int arr[] = {1,2,2,1,1};
    int size = sizeof(arr) / sizeof(arr[0]);

    // Find and print the frequency of each element
    findFrequency(arr, size);

    return 0;
}