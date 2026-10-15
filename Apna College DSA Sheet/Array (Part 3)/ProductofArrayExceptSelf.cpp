
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();

        vector<int> arr(n);
        vector<int> prefix(n);
        vector<int> suffix(n);

        prefix[0] = 1;
        suffix[n - 1] = 1;

        // Calculate prefix products
        for (int i = 1; i < n; i++) {
            prefix[i] = nums[i - 1] * prefix[i - 1];
        }

        // Calculate suffix products
        for (int i = n - 2; i >= 0; i--) {
            suffix[i] = nums[i + 1] * suffix[i + 1];
        }

        // Calculate final answer
        for (int i = 0; i < n; i++) {
            arr[i] = prefix[i] * suffix[i];
        }

        return arr;
    }
};

int main() {
    Solution sol;

    vector<vector<int>> tests = {
        {1, 2, 3, 4},       // Normal case
        {0, 1, 2, 3},       // One zero
        {0, 0, 2, 3},       // Multiple zeros
        {-1, 2, -3, 4},     // Negative values
        {5}                 // Single element
    };

    vector<vector<int>> expected = {
        {24, 12, 8, 6},
        {6, 0, 0, 0},
        {0, 0, 0, 0},
        {-24, 12, -8, 6},   // Corrected expected output
        {1}
    };

    for (int i = 0; i < tests.size(); i++) {
        vector<int> result = sol.productExceptSelf(tests[i]);

        cout << "Test Case " << i + 1 << ": ";
        cout << (result == expected[i] ? "Passed" : "Failed") << '\n';

        cout << "Input: ";
        for (int value : tests[i])
            cout << value << " ";

        cout << "\nExpected: ";
        for (int value : expected[i])
            cout << value << " ";

        cout << "\nOutput: ";
        for (int value : result)
            cout << value << " ";

        cout << "\n\n";
    }

    return 0;
}
