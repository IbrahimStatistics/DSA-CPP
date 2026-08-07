/*
LEETCODE 35 :  SEARCH INSERT POSITION
*/

#include<iostream>
#include<vector>
using namespace std;

int binarySearch(vector<int>& nums, int target);

int searchInsert(vector<int>& nums, int target) {
        int start = 0, end = nums.size()-1;

        while(start<=end){
            int mid = start+(end-start)/2;

            if(nums[mid]==target)
                return mid;
            else if(nums[mid]>target)
                end = mid - 1;
            else 
                start = mid + 1;
        }

        return start;
    }

int main(){
    vector<int> arr = {1,3,5,6};
    int target;
    cout << "Enter target : ";
    cin >> target;

    int result = searchInsert(arr, target);

    cout << "Target should be at index : " << result;

    return 0;
}