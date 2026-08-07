// Find maximum subarray Sum

#include<iostream>
#include<vector>
#include<climits>
using namespace std;

void printSubarray(vector<int> arr){
    for(int start = 0; start<arr.size(); start++){
        for(int end = start; end<arr.size(); end++){
            for(int i = start; i<=end; i++){
                cout << arr[i];
            }
                cout << " | ";
        }
                cout << endl;
    }
}

int maxSum(vector<int> arr){
    int sum = 0;
    int greatest = INT_MIN;

    for(int i = 0; i<arr.size(); i++){
        sum += arr[i];
        
        if(sum<0){
            sum = 0;
        }

        greatest = max(greatest, sum);
    }

    return greatest;
}


int main(){
    vector<int> arr = {-2, 1, -3, 4, -1, 2, 1, -5, 4 };

    cout  << "Maximum Subarray Sum : " << maxSum(arr);

    return 0;
}