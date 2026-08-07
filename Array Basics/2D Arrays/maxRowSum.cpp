// apply linear search on a 2D array
#include<iostream>
#include<climits>
using namespace std;

int main(){
    const int rows = 4;
    const int cols = 5;
    int target = 1;
    int arr[rows][cols] = {
        {3, 7, 1, 9, 4}, // 24
        {6, 2, 8, 0, 5}, // 23
        {1, 4, 3, 6, 7}, // 21
        {9, 0, 2, 8, 1}  // 20
    };
    
    int maxSum = INT_MIN;
    
    for(int i = 0; i<rows; i++){
        int sum = 0;
        for(int j = 0; j<cols; j++){
             sum += arr[i][j];
        }
            maxSum = max(sum, maxSum);
    }
    
    cout << maxSum;
    
    return 0;
}