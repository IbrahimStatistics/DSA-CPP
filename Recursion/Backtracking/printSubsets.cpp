// print all possible subsets for an array containing unique elements
#include <iostream>
#include <vector>
using namespace std;

void getAllSubsets(vector<vector<int>> &result, vector<int> &ans, vector<int> &nums, int i)
{
    if (i == nums.size())
    {
        result.push_back(ans);
        return;
    }

    // inclusion
    ans.push_back(nums[i]);
    getAllSubsets(result, ans, nums, i + 1);

    ans.pop_back();

    // Backtrack / exclusion
    getAllSubsets(result, ans, nums, i + 1);
}

int main()
{
    vector<int> nums = {1, 2, 3};
    vector<vector<int>> result;
    vector<int> ans;

    getAllSubsets(result, ans, nums, 0);

    for (const auto &i : result)
    {
        cout << "{";
        for (auto j : i)
        {
            cout << j << ",";
        }
        cout << "}";
        cout << endl;
    }

    return 0;
}