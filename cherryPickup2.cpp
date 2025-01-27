class Solution {
public:

    int n, m;

    int solve(int i, int j1, int j2, vector<vector<int>>& a, vector<vector<vector<int>>> &dp) {
        // outofboundcase
        if(j1 < 0 || j1 >= m || j2 < 0 || j2 >= m) {
            return -1e8;
        }

        // basecase
    
        if(i == n-1) {
            if(j1 == j2) return a[i][j1];
            else return a[i][j1] + a[i][j2];
        }

        if(dp[i][j1][j2] != -1) return dp[i][j1][j2];

        //exploreallpaths
        int maxi = -1e8;
        for(int dj1 = -1; dj1 <= 1; dj1++) {
            for(int dj2 = -1; dj2 <= 1; dj2++) {
                int val = 0;
                if(j1 == j2) val = a[i][j1];
                
                else val = a[i][j1] + a[i][j2];

                val += solve(i+1, j1+dj1, j2+dj2, a , dp);
                maxi = max(maxi, val);
            }
        }
        return dp[i][j1][j2] = maxi;
    }

    int cherryPickup(vector<vector<int>>& grid) {
        n = grid.size();
        m = grid[0].size();

        vector<vector<vector<int>>> dp(n, vector<vector<int>>(m, vector<int>(m, -1)));

        return solve(0, 0, m-1,grid, dp);
    }
};
