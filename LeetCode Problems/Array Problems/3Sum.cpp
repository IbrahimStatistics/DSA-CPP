#include<iostream>
#include<vector>
#include<set>
#include<tuple>
using namespace std;

vector<vector<int>> threeSum(vector<int>& nums) {
    set<tuple<int,int,int>> uniqueTriplets;

    for(int i = 0; i<nums.size(); i++)
    {
        for(int j = i+1; j<nums.size(); j++)
        {
            for(int k = j+1; k<nums.size(); k++)
            {
                if((nums[i]+nums[j]+nums[k]) == 0){
                    uniqueTriplets.insert({nums[i],nums[j],nums[k]});
                }
            }
        }
    }

    vector<vector<int>> result(uniqueTriplets.begin(),uniqueTriplets.end());
    return result;
}

int main(){
    vector<int> arr = {};
    vector<vector<int>> result = threeSum(arr);
    
    for(auto triplet : result){
        for(int i : triplet)
            cout << i << " ";
        
        cout << endl;
    }

    return 0;
}