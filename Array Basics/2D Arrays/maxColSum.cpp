// Find the maximum column sum
#include<iostream>
#include<climits>
using namespace std;

int main(){
    const int rows = 4;
    const int cols = 5;
    int target = 1;
    int arr[rows][cols] = {
        {3, 7, 1, 9, 4}, // 24  19
        {6, 2, 8, 0, 5}, // 23  13
        {1, 4, 3, 6, 7}, // 21  23
        {9, 0, 2, 8, 1}  // 20  17
    };
    
    int maxSum = INT_MIN;
    
    for(int j = 0; j<cols; j++){
        int sum = 0;
        for(int i = 0; i<rows; i++){
             sum += arr[i][j];
        }
            maxSum = max(sum, maxSum);
    }
    
    cout << maxSum;
    
    return 0;
}