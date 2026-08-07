#include<iostream>
#include<vector>
using namespace std;

bool binarySearch(vector<vector<int>> mat, int target, int rows, int col){
    int row = -1;
    for(int i = 0; i<rows-1; i++){
        if(mat[i][0]<=target && target<=mat[i][col-1]){
            row = i;    
            break;
        }
    }

    int start = 0;
    int end = col-1;
    while(start<=end){
        int mid = start+(end-start)/2;
        if(mat[row][mid]==target){
            return true;
        } else if(mat[row][mid]>target){
            end = mid - 1;
        } else {
            start = mid + 1;
        }
    }
    

    return false;
}

int main(){
    vector<vector<int>> mat = {{1,4,7,11,15},{2,5,8,12,19},{3,6,9,16,22},{10,13,14,17,24},{18,21,23,26,30}}; 
    int rows = mat.size();
    int col = mat[0].size();
    int target = 5;

    bool result = binarySearch(mat, target, rows, col);

    if(result) cout << "present";
    else cout << "absent";

    return 0;
}