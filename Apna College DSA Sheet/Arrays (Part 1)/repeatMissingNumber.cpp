#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();

        vector<int> arr(rows*cols+1, 0);

        for(int i = 0; i<rows; i++) {
            for(int j = 0; j<cols; j++) {
                arr[grid[i][j]] ++;
            }
        }

        int missing, repeating;

        for(int i = 0; i<arr.size(); i++) {
            if(arr[i] == 0)
                missing = i;
            if(arr[i] == 2)
                repeating = i;
        }

        return {repeating, missing};
    }
};

int main() {
    Solution sol;

    vector<vector<int>> test1 = {
        {1, 2},
        {2, 3}
    };

    vector<vector<int>> test2 = {
        {1, 2, 3},
        {2, 4, 5},
        {6, 7, 8}
    };

    vector<vector<int>> test3 = {
        {1, 2, 3},
        {3, 4, 5},
        {6, 7, 8}
    };

    vector<int> res1 = sol.findMissingAndRepeatedValues(test1);
    vector<int> res2 = sol.findMissingAndRepeatedValues(test2);
    vector<int> res3 = sol.findMissingAndRepeatedValues(test3);

    cout << "Test 1: ";
    for (int x : res1) cout << x << " ";
    cout << endl;

    cout << "Test 2: ";
    for (int x : res2) cout << x << " ";
    cout << endl;

    cout << "Test 3: ";
    for (int x : res3) cout << x << " ";
    cout << endl;

    return 0;
}