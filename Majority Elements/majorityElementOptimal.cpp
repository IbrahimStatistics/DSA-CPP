#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int majorityElementOptimal(vector<int> nums){
    sort(nums.begin(), nums.end());
    int n = nums.size();

    int freq = 1; int ans = nums[0]; 
    for(int i = 1; i<n; i++){
        if(nums[i] == nums[i-1]){
            freq++;
            ans = nums[i];
        } else {
            freq = 1;
            ans = nums[i];
        }

        if(freq>n/2) return nums[i];
    }
        return -1;
}

int main(){
    vector<int> nums = {2,2,1,1,1,2,2};

    cout << "Majority Element : " << majorityElementOptimal(nums);

    return 0;
}