#include<iostream>
#include<vector>
using namespace std;

void printArray(vector<int> array);
vector<int> mergedArray(vector<int> nums1,  vector<int> nums2, int m, int n);

void printArray(vector<int> array)
{
    for(int i = 0; i<array.size(); i++)
    {
        cout << array[i] << " ";
    }
}

vector<int> mergedArray(vector<int> nums1,  vector<int> nums2, int m, int n)
{
    vector<int> nums3;
    int i = 0, j = 0;
    int k = 0;

    while(i<m && j<n)
    {
        if(nums1[i]>nums2[j])
        {
            nums3.push_back(nums2[j]);
            j++;
            k++;        
        }
        else //(nums1[i]<nums2[j])
        {
            nums3.push_back(nums1[i]);
            i++;
            k++;
        }
    }

    while(i<m)
    {
        nums3.push_back(nums1[i]);
        k++;
        i++;
    }

    while(j<n)
    {
        nums3.push_back(nums2[j]);
        k++;
        j++;
    }
    
    return nums3;
}

int main()
{
    // vector<int> mergedArray(vector<int> nums1,  vector<int> nums2, int m, int n)
    vector<int> arr1 = {1,2,3,4,5};
    int m = arr1.size();

    vector<int> arr2 = {2,7,8,9};
    int n = arr2.size();

    vector<int> arr3 = mergedArray(arr1, arr2, m, n);
    
    printArray(arr3);

    return 0;
}