#include<iostream>
#include<vector>
#include<algorithm> // <-- Needed for sort
using namespace std;

bool isPossible(vector<int> &arr, int N, int C, int minAllowedDist);
int getDistance(vector<int> &arr, int N, int C);

bool isPossible(vector<int> &arr, int N, int C, int minAllowedDist)
{
    int cows = 1, lastStallPos = arr[0];

    for(int i = 1; i<N; i++)
    {
        if(arr[i]-lastStallPos >= minAllowedDist)
        {
            cows++;
            lastStallPos = arr[i];
        }

        if(cows==C)
        {
            return true;
        }
    }

    return false;
}


int getDistance(vector<int> &arr, int N, int C)
{
    // Sort the array 
    sort(arr.begin(), arr.end());

    // st = 1, end = maxVal-minVal;

    int start = 1, end = arr[N-1]-arr[0], ans = -1;

    while(start<=end)
    {
        int mid = start+(end-start)/2;
        
        if(isPossible(arr, N, C, mid)) // right
        {
            ans = mid;
            start = mid + 1;
        }
        else                            // left
        {
            end = mid - 1;
        }
    }

    return ans;
}


int main()
{
    int N = 5, C = 3;
    vector<int> arr = {1,2,8,4,9};

    cout << getDistance(arr, N, C) << endl;
    return 0;
}