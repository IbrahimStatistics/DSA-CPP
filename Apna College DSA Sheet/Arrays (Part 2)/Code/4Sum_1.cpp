#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int n = nums.size();
        vector<vector<int>> result;
        if (n < 4) return result;

        sort(nums.begin(), nums.end());

        for (int i = 0; i < n - 3; ++i) {
            if (i > 0 && nums[i] == nums[i - 1]) continue; // Skip duplicates for i

            for (int j = i + 1; j < n - 2; ++j) {
                if (j > i + 1 && nums[j] == nums[j - 1]) continue; // Skip duplicates for j

                int left = j + 1, right = n - 1;

                while (left < right) {
                    long long sum = (long long)nums[i] + nums[j] + nums[left] + nums[right];

                    if (sum == target) {
                        result.push_back({nums[i], nums[j], nums[left], nums[right]});

                        // Move pointers past duplicates
                        while (left < right && nums[left] == nums[left + 1]) ++left;
                        while (left < right && nums[right] == nums[right - 1]) --right;

                        ++left;
                        --right;
                    } 
                    else if (sum < target) {
                        ++left;
                    } 
                    else {
                        --right;
                    }
                }
            }
        }
        return result;
    }
};

void printMatrix(const vector<vector<int>>& mat) {
    if (mat.empty()) {
        cout << "[]\n";
        return;
    }

    cout << "[\n";
    for (const auto& row : mat) {
        cout << "  [";
        for (size_t i = 0; i < row.size(); ++i) {
            cout << row[i];
            if (i + 1 < row.size()) cout << ", ";
        }
        cout << "]\n";
    }
    cout << "]\n";
}

int main() {
    Solution sol;

    vector<int> test1 = {1, 0, -1, 0, -2, 2};
    vector<int> test2 = {2, 2, 2, 2, 2};
    vector<int> test3 = {1, 2, 3, 4, 5};
    vector<int> test4 = {5, 5, 3, 5, 1, -5, 1, -2};
    vector<int> test5 = {1, 2};

    cout << "Test 1: nums = {1, 0, -1, 0, -2, 2}, target = 0\n";
    printMatrix(sol.fourSum(test1, 0));

    cout << "\nTest 2: nums = {2, 2, 2, 2, 2}, target = 8\n";
    printMatrix(sol.fourSum(test2, 8));

    cout << "\nTest 3: nums = {1, 2, 3, 4, 5}, target = 10\n";
    printMatrix(sol.fourSum(test3, 10));

    cout << "\nTest 4: nums = {5, 5, 3, 5, 1, -5, 1, -2}, target = 0\n";
    printMatrix(sol.fourSum(test4, 0));

    cout << "\nTest 5: nums = {1, 2}, target = 3\n";
    printMatrix(sol.fourSum(test5, 3));

    return 0;
}