#include<iostream>
#include<vector>
#include<string>
using namespace std;

bool isSafe(const vector<string>& board, int n, int col, int row);
void solveQueens(int col, vector<string>& board, int n,vector<vector<string>>&ans);
vector<vector<string>> NQueens(int n);

bool isSafe(const vector<string>& board, int n, int col, int row) {
    int duprow = row;
    int dupcol = col;   

    // Lower left diagonal
    while(row<n && col>=0) {
        if(board[row][col] == 'Q')
            return false;
    row++;
    col--;
    }
    
    row = duprow;
    col = dupcol;

    // Upper left diagonal
    while(row>=0 && col>=0) {
        if(board[row][col] == 'Q') 
            return false;
        row--;
        col--;
    }
    row = duprow;
    col = dupcol;

    // check left side
    while(col>=0) {
        if(board[row][col] == 'Q')
            return false;
        col--;
    }

    return true;
}

void solveQueens(int col, vector<string>& board, int n, vector<vector<string>>&ans) {
    if(col == n) {
        ans.push_back(board);
        return;
    }

    for(int row = 0; row<n; row++) {
        if(isSafe(board,n,col,row)) {
            board[row][col] = 'Q';
            solveQueens(col+1,board,n,ans);
            board[row][col] = '.';

        }
    }
}

vector<vector<string>> NQueens(int n) {
    vector<vector<string>> ans;
    vector<string> board(n);
    string s(n,'.');
    for(auto i = 0; i<board.size(); i++) {
        board[i] = s;
    }

    solveQueens(0,board,n,ans);
    return ans;   
}

int main() {
    int n = 4;

    vector<vector<string>> result = NQueens(n);

    for(auto &i : result) {
        for(auto j : i) {
            cout << j << " ";
        }
            cout << endl;
    }

    return 0;
}