class Solution {
public:
    void bfs(int row, int col, vector<vector<int>>& vis, vector<vector<char>>& grid) {
        vis[row][col] = 1;
        queue<pair<int, int>> q;

        int n = grid.size();
        int m = grid[0].size();

        q.push({row, col});

        while (!q.empty()) {
            int curRow = q.front().first;
            int curCol = q.front().second;
            q.pop();

            // Traverse in the 4 main directions (up, down, left, right)
            int deltas[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
            for (int i = 0; i < 4; i++) {
                int nrow = curRow + deltas[i][0];
                int ncol = curCol + deltas[i][1];

                if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && grid[nrow][ncol] == '1' && !vis[nrow][ncol]) {
                    vis[nrow][ncol] = 1;
                    q.push({nrow, ncol});
                }
            }
        }
    }

    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<int>> vis(n, vector<int>(m, 0));

        int count = 0;
        for (int row = 0; row < n; row++) {
            for (int col = 0; col < m; col++) {
                if (!vis[row][col] && grid[row][col] == '1') {
                    count++;
                    bfs(row, col, vis, grid);
                }
            }
        }
        return count;
    }
};
