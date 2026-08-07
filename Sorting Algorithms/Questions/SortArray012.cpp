/*
Sort an Array with 0s, 1s and 2s..

arr[] = {2,0,2,1,1,0,1,2,0,0}
*/

#include<iostream>
#include<vector>
using namespace std;


void sortColors(vector<int> &nums);

void sortColors(vector<int>& nums) {
        int col1 = 0, col2 = 0, col3 = 0;

        for(int i = 0; i<nums.size(); i++)
        {   
            if(nums[i] == 0)
                col1++;
            if(nums[i] == 1)
                col2++;
            if(nums[i] == 2)
                col3++;
        }

        int idx = 0;

        for(int i = 0; i<col1; i++)
            nums[idx++] = 0;
        for(int i = 0; i<col2; i++)
            nums[idx++] = 1;
        for(int i = 0; i<col3; i++)
            nums[idx++] = 2;  
}

int main()
{
    vector<int>arr = {2,0,2,1,1,0,1,2,0,0};
    int n = sizeof(arr)/sizeof(int);

    sortColors(arr);

    for(int i : arr)
    {
        cout << i << " ";
    }

    return 0;
}
































/*
#include<iostream>  
using namespace std;

void printArray(int arr[], int n);
void bubbleSort(int arr[], int n);
void selectionSort(int arr[], int n);
void insertionSort(int arr[], int n);

void printArray(int arr[], int n)
{
    for(int i = 0; i<n; i++)
    {
        cout << arr[i] << " ";
    }
}

void bubbleSort(int arr[], int n)
{
    for(int i = 0; i<n-1; i++)
    {
        for(int j = 0; j<n-i-1; j++)
        {
            if(arr[j]>arr[j+1])
                swap(arr[j], arr[j+1]);
        }
    }
}

void selectionSort(int arr[], int n)
{
    for(int i = 0; i<n; i++)
    {
        int minIdx = i;

        for(int j=i+1; j<n; j++)
        {
            if(arr[j]<arr[minIdx])
            {
                minIdx = j;
            }
        }
        
            swap(arr[i], arr[minIdx]);
    }
}

void insertionSort(int arr[], int n)
{
    for(int i = 1; i<n; i++)
    {
        int temp = arr[i];
        for(int j = i-1; j>=0; j--)
        {
            if(arr[])
        }
    }
}

int main()
{
    int arr[] = {4,1,3,5,2};
    int n = sizeof(arr)/sizeof(int);



    return 0;
}

*/