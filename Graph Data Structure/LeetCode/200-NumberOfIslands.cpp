#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void dfs(int i, int j, vector<vector<bool>> &vis,
             vector<vector<char>> &grid) {
        int n = grid.size();
        int m = grid[0].size();

        if (i < 0 || j < 0 || i >= n || j >= m ||
            vis[i][j] || grid[i][j] != '1') {
            return;
        }

        vis[i][j] = true;

        dfs(i + 1, j, vis, grid); // down
        dfs(i - 1, j, vis, grid); // up
        dfs(i, j + 1, vis, grid); // right
        dfs(i, j - 1, vis, grid); // left
    }

    int numIslands(vector<vector<char>> &grid) {
        if (grid.empty() || grid[0].empty()) return 0;

        int islands = 0;
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<bool>> vis(n, vector<bool>(m, false));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == '1' && !vis[i][j]) {
                    dfs(i, j, vis, grid);
                    islands++;
                }
            }
        }
        return islands;
    }
};

int main()
{
    // vector<vector<char>> grid = {
    //     {'1', '1', '1', '1', '0'},
    //     {'1', '1', '0', '1', '0'},
    //     {'1', '1', '0', '0', '0'},
    //     {'0', '0', '0', '0', '0'}}; // output = 1;

    vector<vector<char>> grid = {
        {'1','1','0','0','0'},
        {'1','1','0','0','0'},
        {'0','0','1','0','0'},
        {'0','0','0','1','1'}
    }; // output = 3;

    Solution S;
    cout << "Total Islands: " << S.numIslands(grid);

    return 0;
}