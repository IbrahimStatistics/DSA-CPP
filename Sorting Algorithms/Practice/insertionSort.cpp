// Insertion sort is a sorting algorithm that builds the sorted array one element at a time. It picks each element from the unsorted part and insert it into the correct position in the sorted part.
/*
How it works
1. Start from the second element
2. Compare it with elements before it.
3. Shift larger elements before it.
4. Insert the current element at the correct position.
5. Repeat for all the elements
*/

#include<iostream>
using namespace std;

void printArray(int arr[], int n);
void insertionSort(int arr[], int n);

void insertionSort(int arr[], int n)
{
    for(int i = 1; i<n; i++)      // we consider first element (oth index) as already started
    {
        int temp = arr[i];
        int j = i-1;

        for(; j>=0; j--)
        {
            if(arr[j]>temp)
                //shift
                arr[j+1] = arr[j];
            else
                break; 
        }   

        arr[j+1] = temp;
    }

    

}

void printArray(int arr[], int n)
{
    for(int i = 0; i<n; i++)
    {
        cout << arr[i] << " ";
    }
}

int main()
{
    int arr[] = {4,1,3,2,5};
    int n = sizeof(arr)/sizeof(int);

    insertionSort(arr, n);
    printArray(arr, n);

    return 0;
}