#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        set<vector<int>> s;
        vector<vector<int>> output;

        sort(nums.begin(), nums.end());
        if(nums.size() < 4) return output; 


        for(int i = 0; i<nums.size(); i++) {
            for(int j = i+1; j<nums.size(); j++) {
                int k = j + 1;
                int l = nums.size()-1;

                while(k<l) {
                    long long int sum = nums[i];
                    sum+=nums[j];
                    sum+=nums[k];
                    sum+=nums[l];
                
                    if(sum == target) {
                        s.insert({nums[i], nums[j], nums[k], nums[l]});
                        k++;
                        l--;
                    } else if(sum < target) {
                        k ++;
                    } else if (sum > target) {
                        l --;
                    }
                }

            }
        }

        for(auto quad : s) {
            output.push_back(quad);
        }

        return output;
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