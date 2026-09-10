#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();
        int ans = 0;

        queue<pair<pair<int, int>, int>> q;
        vector<vector<bool>> vis(rows, vector<bool>(cols, false));

        for(int i = 0; i<rows; i++) {
            for(int j = 0; j<cols; j++) {
                if(grid[i][j] == 2) {
                    q.push({{i, j}, 0});
                    vis[i][j] = true;
                }
            }
        }

        // BFS
        while(q.size() > 0) {
            int i = q.front().first.first;
            int j = q.front().first.second;
            int time = q.front().second;
            
            q.pop();
            ans = max(ans, time);
            
            if(i-1>=0 && !vis[i-1][j] && grid[i-1][j] == 1) { // top
                q.push({{i-1, j}, time+1});
                vis[i-1][j] = true;
            }

            if(j+1 <cols && !vis[i][j+1] && grid[i][j+1] == 1) { // right
                q.push({{i, j+1}, time+1});
                vis[i][j+1] = true;
            }

            if(i+1 < rows && !vis[i+1][j] && grid[i+1][j] == 1) { // bottom
                q.push({{i+1, j}, time+1});
                vis[i+1][j] = true;
            }

            if(j-1>=0 && !vis[i][j-1] && grid[i][j-1] == 1) { // left
                q.push({{i, j-1}, time+1});
                vis[i][j-1] = true;
            }
        }

        // check for fresh oranges

        for(int i = 0; i<rows; i++) {
            for(int j = 0; j<cols; j++) {
                if(grid[i][j] == 1 && !vis[i][j]) {
                    return -1;
                }
            }
        }

        return ans;
    }
};

int main() {
    // vector<vector<int>> grid = {{2,1,1},{1,1,0},{0,1,1}}; // output = 4
    vector<vector<int>> grid = {{0,2}}; // output = 0

    Solution S;
    cout << "Min minutes: " << S.orangesRotting(grid);

    return 0;
}