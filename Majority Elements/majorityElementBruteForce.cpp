// Brute force solution to leetcode 169 

#include<iostream>
#include<vector>
using namespace std;

int majorityElement(vector<int> nums){
    int n = nums.size();

    for(int i : nums){
        int frequency = 0;
            for(int j : nums){
                if(i == j)
                    frequency++;     
            }

            if(frequency>n/2) return i;
    }

    return -1;
}

int main(){
    vector<int> nums = {1,2,2,1,1};

    cout << "Majority Element : " << majorityElement(nums);

    return 0;
}