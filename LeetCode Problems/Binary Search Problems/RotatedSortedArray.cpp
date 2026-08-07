#include<iostream>
using namespace std;

int RotatedSortedArray(int arr[], int size, int target);

int main()
{
    int arr[] = {3,4,5,6,7,0,1,2};
    int size = sizeof(arr)/sizeof(int);
    int target;
    cout << "Enter target : ";
    cin >> target;

    int result = RotatedSortedArray(arr, size, target);

    if(result!=-1)
        cout << "Target found at index : " << result;
    else
        cout << "Target not found!";

    return 0;
}


int RotatedSortedArray(int arr[], int size, int target)
{
    int start = 0;
    int end = size - 1;
    
    while(start<=end)
    {
        int mid = start+(end-start)/2;
        if(arr[mid] == target)
            return mid;

        if(arr[start]<=arr[mid])    // Case of Left sorted array
        {
            if(arr[start]<=target && target<=arr[mid])  // Now checking if target value lies in this region
                end = mid - 1;       // If yes the change the end point to one less than the mid 
            else
                start = mid + 1;    // If  the target does not lie in this region then this indicates that the target is in right half of the array, hence change the starting point to mid + 1
        }
        else 
        {
            // Right Sorted Array
            if(arr[mid]<=target && target<=arr[end])
                start = mid + 1;
            else
                end = mid - 1;
        }
    }

    return -1;
}
