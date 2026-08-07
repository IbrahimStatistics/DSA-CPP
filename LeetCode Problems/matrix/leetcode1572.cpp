#include<iostream>
#include<vector>
using namespace std;

int diagonalSum(vector<vector<int>>& mat) {
        int dim = mat.size();
        int pds = 0;
        int sds = 0;
        bool odd = (dim%2 != 0);

        int i = 0, j = 0;
        int mid = (dim-1)/2;

        while(i<dim && j<dim){
            pds += mat[i][j];

            if(odd && i==mid && j==mid){
                i++, j++;
                continue;
            }
            
            sds += mat[i][dim-1-j];

            i++, j++;
        }
        
        return pds + sds;
    }

int main(){
    vector<vector<int>> arr = {{1,1,1,1},{1,1,1,1},{1,1,1,1},{1,1,1,1}};
    
    cout << diagonalSum(arr);
    
    return 0;
}
