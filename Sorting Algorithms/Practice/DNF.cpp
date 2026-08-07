/*
DNF - Dutch National Flag Algorithm
*/

#include<iostream>
#include<vector>
using namespace std;


void sortColors(vector<int>& nums) {
        int low = 0, mid = 0, high = nums.size()-1;

        while(mid<=high)
        {
            if(nums[mid]==0){
                swap(nums[mid],nums[low]);
                mid++;
                low++;
            }
                
            else if(nums[mid]==2){
                swap(nums[mid],nums[high]);
                high--;
            }
            else if(nums[mid]==1)
                mid++;
        }
    }

int main()
{
    vector<int> arr= {2,0,2,1,1,0};
    int n = sizeof(arr)/sizeof(int);
    
    // sort
    
    sortColors(arr);
    
    for(int i = 0; i<n; i++)
    {
        cout << arr[i] << " ";
    }
    
    return 0;
}




// 9,10,11 --> 11,9,10