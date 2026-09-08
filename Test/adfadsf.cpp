#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        if(nums.size() == 1 || nums.size() == 2) {
            return nums[0];
        }

        int st = 0;
        int end = nums.size()-1;

        while(st <= end) {
            int mid = st + (end-st)/2;

            if(nums[mid] != nums[mid+1] && nums[mid] != nums[mid-1]) {
                return nums[mid];
            } else if (nums[mid] == nums[mid+1]) {
                st = mid + 1;
            } else if (nums[mid] == nums[mid-1]) {
                end = mid + 1;
            }
        }
        return -1;
    }   
};