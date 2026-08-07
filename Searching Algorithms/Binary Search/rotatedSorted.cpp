// Search in Rotated Sorted Array 
// ascending order; distinct values

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
    {
        cout << "Target found at index : " << result;
    }
    else
    {
        cout << "Target not found!";
    }

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
        {
            return mid;
        }

        if(arr[start]<=arr[mid])
        {
            // Left sorted array
            if(arr[start]<=target && target<=arr[mid])
            {
                end = mid - 1;
            } 
            else
            {
                start = mid + 1;
            }
        }
        else 
        {
            // Right Sorted Array
            if(arr[mid]<=target && target<=arr[end])
            {
                start = mid + 1;
            }
            else
            {
                end = mid - 1;
            }
        }
    }

    return -1;
}

// int RotatedSortedArray(int arr[], int size, int target)
// {
//     int start = 0;
//     int end = size - 1;
    
//     while(start<=end)
//     {
//         int mid = start + (end-start)/2;

//         if(arr[start]<=arr[end])
//         {
//             // Proceed with Binary Search in left half
//             if(arr[start]<=target && target<=arr[mid])
//             {
//                 end = mid-1;
//             }
//         }
//         else if(arr[mid]<=arr[end])
//         {
//             // Proceed with Binary Search in Right Half
//             if(arr[mid]<=target && target<=arr[end])
//             {
//                 start = mid+1;
//             }
//         }
//         else if(arr[mid] == target) 
//         {   
//             return mid;
//         }
//     }

//     return -1;
// }











































// Lets write the code to implement binary search algorithm in C++ array

/*
#include<iostream>
using namespace std;

int BinarySearch(int arr[], int size, int target);

int main()
{
    int arr[] = {-1, 0, 3, 4, 5, 9, 12};
    int size = sizeof(arr)/sizeof(int);

    int target;
    cout << "Enter target : ";
    cin >> target;

    int result = BinarySearch(arr, size, target);

    cout << "Using Binary Search Algorithm" << '\n';

    if(result != -1)
    {
        cout << "Target found at index : " << result;
    }
    else 
    {
        cout << "Target not found";
    }

    return 0;
}

int BinarySearch(int arr[], int size, int target)
{
    int start = 0;
    int end = size-1;

    while (start<=end)
    {
        int mid = (start+(end-start))/2;

        if(target>arr[mid])
        {
            start = mid + 1;
        }
        else if(target<arr[mid])
        {
            end = mid - 1;
        }
        else if(target == arr[mid])
        {
            return mid;
        }
    }


    return -1;
}
*/