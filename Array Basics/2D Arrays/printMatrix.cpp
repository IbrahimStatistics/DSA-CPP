#include<iostream>
using namespace std;

int main(){
    int matrix[3][3] = {{2,4,6},{8,10,12},{14,16,18}};
    int row = 3;
    int col = 3;
    
    for(int i = 0; i<row; i++){
        for(int j = 0; j<col; j++){
            cout << matrix[i][j] << " ";
        }
        
        cout << endl;
    }
    
    return 0;
}