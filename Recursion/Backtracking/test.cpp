// Write code to print all possible subsets of a given set

#include <iostream>
#include <vector>
using namespace std;

void getAllPermutations(vector<int> &nums, vector<vector<int>> &result, int i)
{
    if (i == nums.size())
    {
        result.push_back(nums);
        return;
    }

    for (int j = 0; j < nums.size(); j++)
    {
        swap(nums[i], nums[j]);
        getAllPermutations(nums, result, i + 1);
        swap(nums[i], nums[j]);
    }
}

int main()
{
    vector<vector<int>> result;

    vector<int> nums = {1, 2, 3};

    getAllPermutations(nums, result, 0);

    for (auto i : result)
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