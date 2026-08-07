// apply linear search on a 2D array

#include<iostream>
using namespace std;

int main(){
    const int rows = 4;
    const int cols = 5;
    int target = 1;
    int arr[rows][cols] = {
        {3, 7, 1, 9, 4},
        {6, 2, 8, 0, 5},
        {1, 4, 3, 6, 7},
        {9, 0, 2, 8, 1}
    };
    
    
    // Linear Search Algorithm
    
    for(int i = 0; i<rows; i++){
        for(int j = 0; j<cols; j++){
            if(target == arr[i][j]){
                cout << "Target found in row " << i << " and col " << j;
                cout << endl;
                break;
            }
        }
    }
    
    return 0;
}