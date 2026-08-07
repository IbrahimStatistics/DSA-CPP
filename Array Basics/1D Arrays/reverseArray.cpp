// Reverse an array

#include<iostream>
using namespace std;

void printArray(int arr[], int size);
void reverseArray(int arr[], int size);

void printArray(int arr[], int size)
{
    int n = size-1;
    for(int i = 0; i<=n; i++)
    {
        cout << arr[i] << " ";
    }
}

void reverseArray(int arr[], int size)
{
    int n = size - 1;
    for(int i = 0; i<=n/2; i++)
    {
        swap(arr[i], arr[n-i]);
    }
}


int main()
{
    int arr[] = {1,2,3,4,5,6,7,8};
    int size = sizeof(arr)/sizeof(int);
    
    cout << "Before reversing" << '\n';
    printArray(arr, size);
    
    cout << '\n';
    
    cout << "After reversing" << '\n';
    reverseArray(arr, size);
    printArray(arr,size);
    
    return 0;
}