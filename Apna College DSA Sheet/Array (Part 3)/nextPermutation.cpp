#include<bits/stdc++.h>
using namespace std;


#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        int i = n - 2;

        while (i >= 0 && nums[i] >= nums[i + 1]) {
            i--;
        }

        if (i >= 0) {
            int j = n - 1;

            while (nums[j] <= nums[i]) {
                j--;
            }

            swap(nums[i], nums[j]);
        }

        // Step 3: Reverse the suffix
        reverse(nums.begin() + i + 1, nums.end());
    }
};



int main() {
    Solution sol;

    vector<vector<int>> tests = {
        {1, 2, 3},       // Normal case
        {1, 3, 2},       // Middle permutation
        {3, 2, 1},       // Last permutation
        {1, 1, 5},       // Duplicate elements
        {1},             // Single element
        {1, 2},           // Two elements, ascending
        {2, 1},           // Two elements, descending
        {1, 3, 5, 4, 2},  // Pivot in the middle
        {2, 1, 5, 4, 3},  // Pivot near the beginning
        {2, 2, 3, 1},     // Multiple duplicate elements
        {1, 5, 1},        // Repeated values
        {1, 2, 3, 4, 5}   // Fully ascending
    };

    for (int t = 0; t < tests.size(); t++) {
        vector<int> nums = tests[t];

        cout << "Test Case " << t + 1 << ": ";
        cout << "Input: ";

        for (int x : nums)
            cout << x << " ";

        sol.nextPermutation(nums);

        cout << "| Output: ";
        for (int x : nums)
            cout << x << " ";

        cout << '\n';
    }

    return 0;
}