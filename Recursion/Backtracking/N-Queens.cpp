#include <bits/stdc++.h> // includes all standard C++ libraries

using namespace std;

// Define a class Solution to encapsulate the N-Queens problem solution
class Solution
{
public:
  // Function to check if it's safe to place a queen at board[row][col]
  // Store the original row and column
  bool isSafe1(int row, int col, vector<string> board, int n)
  {
    int duprow = row;
    int dupcol = col;

    // Check the upper-left diagonal
    while (row >= 0 && col >= 0)
    {
      if (board[row][col] == 'Q') // If another queen is found, it's unsafe
        return false;
      row--;
      col--;
    }

    // Reset row and col
    col = dupcol;
    row = duprow;
    // Check the left side of the current row
    while (col >= 0)
    {
      if (board[row][col] == 'Q') // If another queen is found in the row, unsafe
        return false;
      col--;
    }

    // Reset row and col again
    row = duprow;
    col = dupcol;
    // Check the lower-left diagonal
    while (row < n && col >= 0)
    {
      if (board[row][col] == 'Q') // If another queen is found, unsafe
        return false;
      row++;
      col--;
    }
    // If no queen found in any direction, it's safe
    return true;
  }

public:
  // Recursive function to solve N-Queens column by column
  void solve(int col, vector<string> &board, vector<vector<string>> &ans, int n)
  {
    // If all columns are filled, store the board configuration
    if (col == n)
    {
      ans.push_back(board);
      return;
    }
    // Try placing a queen in every row of the current column
    for (int row = 0; row < n; row++)
    {
      // Check if it's safe to place a queen at [row][col]
      if (isSafe1(row, col, board, n))
      {
        board[row][col] = 'Q';         // Place queen
        solve(col + 1, board, ans, n); // Recurse for next column
        board[row][col] = '.';         // Backtrack and remove queen
      }
    }
  }

public:
  // Main function to solve the N-Queens problem
  vector<vector<string>> solveNQueens(int n)
  {
    vector<vector<string>> ans; // Store all possible solutions
    vector<string> board(n);    // Represent the chessboard
    string s(n, '.');           // Initialize empty row with '.'
    for (int i = 0; i < n; i++)
    {
      board[i] = s; // Fill the board with empty rows
    }
    solve(0, board, ans, n); // Start recursion from column 0
    return ans;              // Return all valid solutions
  }
};

int main()
{
  int n = 4;                                        // Define the size of the chessboard (4x4) and number of queens
  Solution obj;                                     // Create object of Solution class
  vector<vector<string>> ans = obj.solveNQueens(n); // Get all solutions for N-Queens

  // Print all valid board arrangements
  for (int i = 0; i < ans.size(); i++)
  {
    cout << "Arrangement " << i + 1 << "\n"; // Display arrangement number
    for (int j = 0; j < ans[0].size(); j++)
    {
      cout << ans[i][j]; // Print each row of the board
      cout << endl;
    }
    cout << endl; // Separate arrangements by newline
  }
  return 0; // Exit program
}
