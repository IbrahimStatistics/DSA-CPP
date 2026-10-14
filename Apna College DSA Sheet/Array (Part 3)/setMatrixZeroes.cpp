
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        if (matrix.empty()) return;

        int n = matrix.size();
        int m = matrix[0].size();

        vector<bool> row(n, false);
        vector<bool> col(m, false);

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (matrix[i][j] == 0) {
                    row[i] = true;
                    col[j] = true;
                }
            }
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (row[i] || col[j]) {
                    matrix[i][j] = 0;
                }
            }
        }
    }
};

void printMatrix(const vector<vector<int>>& matrix) {
    for (const auto& row : matrix) {
        for (int val : row) {
            cout << val << " ";
        }
        cout << '\n';
    }
}

int main() {
    Solution sol;

    // Test Case 1: Zero in the middle
    vector<vector<int>> matrix1 = {
        {1, 1, 1},
        {1, 0, 1},
        {1, 1, 1}
    };

    // Test Case 2: Multiple zeros
    vector<vector<int>> matrix2 = {
        {0, 1, 2, 0},
        {3, 4, 5, 2},
        {1, 3, 1, 5}
    };

    // Test Case 3: Zero in the first row
    vector<vector<int>> matrix3 = {
        {1, 0, 3},
        {4, 5, 6},
        {7, 8, 9}
    };

    // Test Case 4: Zero in the first column
    vector<vector<int>> matrix4 = {
        {1, 2, 3},
        {0, 5, 6},
        {7, 8, 9}
    };

    // Test Case 5: No zeros
    vector<vector<int>> matrix5 = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };

    // Test Case 6: All zeros
    vector<vector<int>> matrix6 = {
        {0, 0},
        {0, 0}
    };

    vector<vector<vector<int>>> tests = {
        matrix1, matrix2, matrix3,
        matrix4, matrix5, matrix6
    };

    for (int i = 0; i < tests.size(); i++) {
        cout << "\nTest Case " << i + 1 << ":\n";

        sol.setZeroes(tests[i]);
        printMatrix(tests[i]);
    }

    return 0;
}
