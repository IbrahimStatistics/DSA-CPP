// Print all possible subsets of array
#include <iostream>
#include <vector>
using namespace std;

void getAllPermutations(vector<vector<int>> &ans, vector<int> &nums, int idx)
{
    if (idx == nums.size())
    {
        ans.push_back(nums);
        return;
    }

    for (int i = idx; i < nums.size(); i++)
    {
        swap(nums[idx], nums[i]);
        getAllPermutations(ans, nums, idx + 1);
        swap(nums[idx], nums[i]);
    }
}

int main()
{
    vector<int> nums = {1, 2, 3};
    vector<vector<int>> result;
    getAllPermutations(result, nums, 0);

    for (auto i : result)
    {
        for (int j : i)
        {
            cout << j;
        }
        cout << endl;
    }

    return 0;
}