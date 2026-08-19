#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        unordered_map<int, int> maps;
        for(int i = 0; i<nums.size(); i++) 
        {
            if(maps.find(nums[i])!=maps.end()) {
                return true;
            }

            maps[nums[i]] = i;
        }

        return false;
    }
};