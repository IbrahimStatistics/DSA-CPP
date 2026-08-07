// KADANE'S ALGORITHM

#include<iostream>
#include<limits.h>
using namespace std;

int kadane(int arr[], int size);

int main()
{
	int arr[] = {-2,1,-3,4,-1,2,1,-5,4};
	int size = sizeof(arr)/sizeof(int);

	cout << "Maximum Sum : " << kadane(arr, size);

	return 0;
}

int kadane(int arr[], int size)
{
	int maxSum = INT_MIN, currSum = 0;

	for(int i = 0;i<size;i++)
	{
		currSum += arr[i];
		maxSum = max(currSum, maxSum);

		if(currSum<0)
		{
			currSum = 0;
		}
	}
	
	return maxSum;
}