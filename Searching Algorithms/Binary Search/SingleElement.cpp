// Single element in sorted array problem

#include<iostream>
#include<vector>
using namespace std;

int SingleElement(vector<int> arr);

int main()
{
    vector<int> arr1 = {1,1,2,3,3,4,4,8,8};
    vector<int> arr2 = {3,3,7,7,10,11,11};
    
    cout << "Single Element in array 1 : " << SingleElement(arr1);
    cout << "Single Element in array 2 : " << SingleElement(arr2);

    return 0;
}

int SingleElement(vector<int> arr)
{
    int start = 0, end = arr.size()-1;

    while(start<=end)
    {
        int mid = start+(end-start)/2;
        
        if(mid == 0 && arr[mid]!=arr[mid+1])    return arr[mid];
        if(mid == end && arr[mid-1]!=arr[mid])  return arr[mid];
        
        if(arr[mid-1]==arr[mid] || arr[mid]==arr[mid+1])
        {}

    }

    return -1;
}
