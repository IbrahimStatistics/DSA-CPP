/*
=> Painters Partition Problem
- Given are N boards of length of each given in the form of array, and M painters, such that each painter takes 1 unit of time to paint 1 unit of the board.
- The task is to find the minimum time to point all boards under the constraints that any painter will only paint continous sections of board.
*/

#include<iostream>
#include<vector>
#include<climits>
using namespace std;

int minTimeToPaint(vector<int>& arr, int n, int m);
bool isValid(vector<int>& arr, int n, int m, int maxAllowedTime);

bool isValid(vector<int>& arr, int n, int m, int maxAllowedTime)
{
    int painter = 1, time = 0;

    for(int i = 0; i < n; i++)
    {
        if(arr[i] > maxAllowedTime)
            return false;

        if(time + arr[i] <= maxAllowedTime)
        {
            time += arr[i];
        }
        else
        {
            painter++;
            time = arr[i];
        }
    }

    return painter <= m;
}

int minTimeToPaint(vector<int>& arr, int n, int m)
{
    int sum = 0, maxVal = 0;
    for(int i = 0; i < n; i++)
    {
        sum += arr[i];
        maxVal = max(maxVal, arr[i]);
    }

    int start = maxVal, end = sum, ans = -1;

    while(start <= end)
    {
        int mid = start + (end - start) / 2;

        if(isValid(arr, n, m, mid))
        {
            ans = mid;
            end = mid - 1;
        }
        else
        {
            start = mid + 1;
        }
    }

    return ans;
}

int main()
{
    vector<int> arr = {1,2,8,4,9};
    int n = arr.size();
    int m = 3;

    cout << minTimeToPaint(arr, n, m) << endl;

    return 0;
}

