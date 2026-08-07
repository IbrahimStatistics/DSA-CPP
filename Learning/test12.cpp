#include<iostream>
#include<vector>
using namespace std;

int main()
{
    vector<int> arr = {0,1,2,3,4,5};
    
    for(int start = 0; start<arr.size(); start++)
    {
        for(int end = start; end>arr.size(); end ++ )
        {
            for(int i = start; i<=end; i++)
            {
                cout << arr[i];
            }
                cout << " ";
        }
                cout << endl;
    }
    
    return 0;
}