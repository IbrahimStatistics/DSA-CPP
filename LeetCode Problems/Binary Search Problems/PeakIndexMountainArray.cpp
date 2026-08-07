// The Peak index mountain array Problem 


#include<iostream>
#include<vector>
using namespace std;

int PeakIndex(vector<int> arr);

int main()
{
    vector<int> arr = {0,1,0};
    
    int result = PeakIndex(arr);
    cout << "Peak : " << result;
    
    return 0;
}

int PeakIndex(vector<int> arr)
{
int start = 1, end = arr.size() - 2;

    while(start<=end)
    {
        int mid = start+(end-start)/2;

        if(arr[mid-1]<arr[mid] && arr[mid+1]<arr[mid])
            return mid;
        
        else if(arr[mid]>arr[mid-1])    // Mid is on the left slope 
            start = mid + 1;
        
        else 
            end = mid - 1;
    }

    return -1;
}



// Find the largest number in the array 
// Brute Force Approach 
/*
#include<iostream>
#include<vector>
using namespace std;

int PeakIndex(vector<int> arr);

int main()
{
    vector<int> arr = {0,3,8,9,5,2};
    
    int result = PeakIndex(arr);
    
    cout << "Peak Index : " << result;
    
    return 0;
}

int PeakIndex(vector<int> arr){
    int max = 0;
    
    
    for(int i = 1; i<arr.size(); i++){
        if(arr[i]>arr[max])
        {
            max = i;
        }
    }
    
    return max;
}
*/

