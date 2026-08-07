// Binary Search Algorithm can be applied only on sorted array 
// follows a divide and conquer strategy

#include<iostream>
#include<vector>
using namespace std;

int binarySearch(vector<int>nums, int target)
{
    int st = 0,end = nums.size()-1;

    while(st<=end)
    {
        int mid = (st+end)/2;

        if(target>nums[mid])
        {
            st = mid + 1;
        } else if(target < nums[mid]){
            end = mid - 1;
        } else {
            return mid;
        }

    }

    return -1;
}

int main()
{
    vector<int> arr1 = {-1, 0, 3, 4, 5, 9, 12}; // even 
    int tar1 = 12;

    cout << binarySearch(arr1, tar1) << endl;

    vector<int> arr2 = {-1, 0, 3, 5, 9, 12};    //odd
    int tar2 = 0;



    return 0;
}