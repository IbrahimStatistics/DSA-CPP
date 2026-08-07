/*
1. Two Sum
*/

#include<iostream>
#include<vector>
using namespace std;

vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> ans;

        for(int i = 0; i<nums.size(); i++){
            for(int j = i+1; j<nums.size(); j++){
                if(nums[i]+nums[j]==target){
                    ans.push_back(i);
                    ans.push_back(j);
                    return ans;
                }
            }
        }


        return {};
}

int main(){
    // return indices that add up to target value
    vector<int> arr = {2,7,11,15};
    int target;
    cout << "Enter target : ";
    cin >> target;

    vector<int> result = twoSum(arr, target);

    cout << "Result" << endl;
    for(int i : result){
        cout << i << " "; // prints index
    }


    return 0;
}