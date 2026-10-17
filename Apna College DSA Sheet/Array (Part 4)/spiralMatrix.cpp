#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int rows = matrix.size();
        int cols = matrix[0].size();

        int top = 0, bottom = rows - 1;
        int left = 0, right = cols - 1;

        vector<int> result;

        while (top <= bottom && left <= right) {

            for (int j = left; j <= right; j++) {
                result.push_back(matrix[top][j]);
            }
            top++;

            for (int i = top; i <= bottom; i++) {
                result.push_back(matrix[i][right]);
            }
            right--;

            if (top <= bottom) {
                for (int j = right; j >= left; j--) {
                    result.push_back(matrix[bottom][j]);
                }
                bottom--;
            }

            if (left <= right) {
                for (int i = bottom; i >= top; i--) {
                    result.push_back(matrix[i][left]);
                }
                left++;
            }
        }

        return result;
    }
};


int main() {
    Solution sol;

    vector<pair<vector<vector<int>>, vector<int>>> tests = {
        {
            {{1,2,3}, {4,5,6}, {7,8,9}},
            {1,2,3,6,9,8,7,4,5}
        },
        {
            {{1,2,3,4}, {5,6,7,8}, {9,10,11,12}},
            {1,2,3,4,8,12,11,10,9,5,6,7}
        },
        {
            {{1}},
            {1}
        },
        {
            {{1,2,3,4}},
            {1,2,3,4}
        },
        {
            {{1}, {2}, {3}, {4}},
            {1,2,3,4}
        },
        {
            {{1,2}, {3,4}},
            {1,2,4,3}
        },
        {
            {{1,2,3}, {4,5,6}},
            {1,2,3,6,5,4}
        },
        {
            {{1,2}, {3,4}, {5,6}},
            {1,2,4,6,5,3}
        },
        {
            {{1,2,3}, {4,5,6}, {7,8,9}, {10,11,12}},
            {1,2,3,6,9,12,11,10,7,4,5,8}
        },
        {
            {{1,2,3,4,5}},
            {1,2,3,4,5}
        }
    };

    int passed = 0;

    for (int t = 0; t < tests.size(); t++) {
        vector<vector<int>> matrix = tests[t].first;

        vector<int> actual = sol.spiralOrder(matrix);
        vector<int> expected = tests[t].second;

        if (actual == expected) {
            cout << "Test " << t + 1 << ": PASS\n";
            passed++;
        } else {
            cout << "Test " << t + 1 << ": FAIL\n";

            cout << "Expected: ";
            for (int x : expected) cout << x << " ";

            cout << "\nActual:   ";
            for (int x : actual) cout << x << " ";

            cout << "\n";
        }
    }

    cout << "\nPassed: " << passed
         << "/" << tests.size() << "\n";

    return 0;
}
