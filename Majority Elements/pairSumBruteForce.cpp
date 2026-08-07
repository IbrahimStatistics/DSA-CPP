// Brute force approach for two sum
// Return pair in sorted array with target sum

#include<iostream>
#include<vector>
using namespace std;

vector<int> pairSum(vector<int> nums, int target);

int main()
{
    vector<int> nums = {2,7,11,15};
    
    int target;
    cout << "Enter target sum : ";
    cin >> target;

    vector<int> ans = pairSum(nums,target);
    cout << ans[0] << "," << ans[1]<< endl;

    return 0;
}

vector<int> pairSum(vector<int> nums, int target)
{
    vector<int> ans;

    for(int i = 0; i<nums.size();i++)
    {
        for(int j = i+1; j<nums.size(); j++)
        {
            if(nums[i]+nums[j]==target)
            {
                ans.push_back(i);
                ans.push_back(j);
                return ans;

            }
        }
    }

    return ans;
}
