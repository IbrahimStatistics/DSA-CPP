// Online C++ compiler to run C++ program online
#include <iostream>
#include<vector>
#include<algorithm>

int main() {
    vector<int> nums = {1,2,3,4,5,6,7};
    
    reverse(nums.end(),nums.begin());
    
    sort(nums.begin(),nums.begin()+k);
    sort(nums.begin()+k, nums.end());
    
    for(int i : nums) cout << i << " "; 
    
    return 0;
}