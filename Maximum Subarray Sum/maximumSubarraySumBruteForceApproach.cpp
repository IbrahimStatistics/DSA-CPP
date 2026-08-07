#include<iostream>
#include<vector>
using namespace std;

int main()
{
    int arr[] = {1,2,3,4,5};
    int size = sizeof(arr)/sizeof(int);
    int maxSum = INT64_MIN;

    for(int start = 0; start<size; start++)
    {
        int currSum = 0;
        for(int end = start; end<size; end++)
        {
            currSum += arr[end];
            maxSum = max(currSum, maxSum);
        }
    }

    cout << "max subarray sum = " << maxSum << endl;

    return 0;
}