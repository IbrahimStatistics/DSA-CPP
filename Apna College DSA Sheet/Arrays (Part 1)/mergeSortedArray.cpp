#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i = 0;
        int j = 0;

        while(j<nums2.size()) {
            if(nums1[i] < nums2[j]) {
                
            } else if(nums1[i] > nums2[j]) {

            } else if(nums1[i] == nums2[j]) {

            }
        }
    }
};

int main() {
    Solution sol;

    vector<int> nums1 = {1, 2, 3, 0, 0, 0};
    vector<int> nums2 = {2, 5, 6};
    sol.merge(nums1, 3, nums2, 3);

    vector<int> nums3 = {1, 2, 0, 0};
    vector<int> nums4 = {3, 4};
    sol.merge(nums3, 2, nums4, 2);

    vector<int> nums5 = {0, 0, 0, 0};
    vector<int> nums6 = {1, 2, 3};
    sol.merge(nums5, 0, nums6, 3);

    cout << "Test 1: ";
    for (int x : nums1) cout << x << " ";
    cout << endl;

    cout << "Test 2: ";
    for (int x : nums3) cout << x << " ";
    cout << endl;

    cout << "Test 3: ";
    for (int x : nums5) cout << x << " ";
    cout << endl;

    return 0;
}