#include<iostream>
#include<vector>
using namespace std;

void subarray(vector<int> arr)
{   
    for(int start = 0; start<arr.size(); start++)
    {
        for(int end = start; end<arr.size(); end++)
        {
            for(int i = start; i<=end; i++)
            {
                cout << arr[i] << ",";
            }
                cout << " | ";
        }
                cout << endl;
    }
}

int main()
{
    vector<int> vec = {1,2,3,4,5,6,7};
    // vector<int> vec = {2,7,11,15};
    subarray(vec);
}