// THIS IS EVERYTHIG IN MAXIMUM SUB ARRAY SUM PROBLEM

#include<iostream>
#include<vector>
#include<limits.h>
using namespace std;

void printSub(vector<int> array);
int bruteForce(vector<int> array);
int kadane(vector<int> array);

int main()
{
	vector<int> array = {5, -3, 0, 12, -7, 42, -15, 8, -1, 0, 23, -9};

	// Print all the sub arrays
	cout<< "=> All Possible Subarrays" << '\n';
	printSub(array);
	cout << "\n";

	cout << "=> Maximum Subarray sum using brute force approach" << '\n';
	cout << "	Max Sum = " << bruteForce(array) << '\n';
	
	cout << "=> Maximum Subarray sum using kadane's algorithm" << '\n';
	cout << "	Max Sum = " << kadane(array) << '\n';

	return 0;
}

void printSub(vector<int> array)
{
	for(int start = 0; start<array.size(); start++)
	{
		for(int end = start; end<array.size(); end++)
		{
			for(int i = start; i<=end; i++)
			{
				cout << array[i];
			}
				cout << " | ";
		}
				cout << '\n';
	}
}


int bruteForce(vector<int> array)
{
	int maxSum = INT_MIN;
	for(int start = 0; start<array.size(); start++)
	{
		int currSum = 0;
		for(int end = 0; end<array.size(); end++)
		{
			currSum += array[end];
			maxSum = max(currSum, maxSum);
		}
	}
	return maxSum;
}

int kadane(vector<int> array)
{
	int maxSum = INT_MIN,currSum = 0;
	for(int i = 0;i<array.size();i++)
	{
		currSum+=array[i];
		maxSum = max(currSum, maxSum);

		if(currSum < 0)
		{
			currSum = 0;
		}
	}

	return maxSum;
}
