// recursive solution to the N queens problem
#include<iostream>
#include<vector>
#include<string>
using namespace std;

bool isSafe(int row,int col,vector<string>&board,int n) {
    int duprow = row;
    int dupcol = col;
    
    // upper left diagonal
    while(row>=0 && col>=0) {
        if(board[row][col] == 'Q') 
            return false;
        row--;
        col--;
    }
    
    row = duprow;
    col = dupcol;
    
    // lower left diagonal
    while(row<n && col>=0) {
        if(board[row][col] == 'Q') 
            return false;
        row++;
        col--;
    }
    row = duprow;
    col = dupcol;
    // check towards left
    while(col>=0) {
        if(board[row][col] == 'Q')
            return false;
        col--;
    }
    
    return true;
}

void solve(int col, int n, vector<string>& board, vector<vector<string>>&ans) {
    if(col == n) {
        ans.push_back(board);
        return;
    }
    
    for(int row = 0; row<n; row++) {
        if(isSafe(row,col,board,n)) {
            board[row][col] = 'Q';
            solve(col+1,n,board,ans);
            board[row][col] = '.';
        }
    }
}

vector<vector<string>> NQueens(int n) {
    vector<vector<string>> ans;
    vector<string> board(n);
    string s(n,'.');
    
    for(int i = 0; i<n; i++) {
        board[i] = s;
    }
    
    solve(0,n,board,ans);
    return ans;
}

int main() {
    int n = 4;
    vector<vector<string>> result;
    
    result = NQueens(n);
    
    for(auto &i : result) {
        for(auto j : i) 
            cout << j << " | ";
        cout << endl;
    }
    
    return 0;
}