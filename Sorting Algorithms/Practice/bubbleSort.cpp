/*
Bubble Sort Algorithm
-> Compare adjacent elements and swap them if they are in the wrong order. Repeat this  until the array is sorted.
-> Time Complexity (Worst Case) : O(n^2) 
*/

#include<iostream>
using namespace std;

void bubbleSort(int arr[], int n) //O(n^2)
{
    bool isSwap = false;

    for(int i = 0; i<n; i++)
    {
        for(int j = 0; j<n-i-1; j++)
        {
            if(arr[j]>arr[j+1])
            {
                swap(arr[j],arr[j+1]); 
                isSwap = true;
            }
        }

        if(!isSwap){// array is already sorted
        
        }
    }
}

void printArray(int arr[], int n)
{
    for(int i = 0;i<n; i++)
    {
        cout << arr[i] << " ";
    }

    cout << endl;
}

int main()
{
    int n = 5;
    int arr[] = {4,1,5,2,3};

    bubbleSort(arr, n);
    cout << endl;

    printArray(arr,n);
    cout << endl;
    
    return 0;
}