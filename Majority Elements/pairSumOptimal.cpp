// PAIR SUM OPTIMAL APPROACH

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

    vector<int> result;
    result = pairSum(nums, target);

    for(int i : result){
        cout << i << " " ;
    }

    return 0;
}

vector<int> pairSum(vector<int> nums,int target){
    vector<int> result;

    int size = nums.size();
    int i = 0, j = size-1;
    
    while(i<j)
    {
        int pairSum = nums[i] + nums[j];

        if(pairSum > target){
            j--;
        } else if(pairSum < target){
            i++;
        } else if(pairSum == target){
            result.push_back(i);
            result.push_back(j);
            return result;
        }
    }
    return result;
}