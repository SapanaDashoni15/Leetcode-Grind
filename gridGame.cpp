class Solution {
public:
    long long gridGame(vector<vector<int>>& grid) {
        long long mini = LLONG_MAX;
        long long row1sum = accumulate(grid[0].begin(), grid[0].end(), 0LL);

        long long row2sum = 0;

        for(int i = 0; i<grid[0].size(); i++) {
            row1sum -= grid[0][i];
            mini = min(mini, max(row1sum, row2sum));
            row2sum += grid[1][i];
        }

        return mini;
    }
};


/*
- minimise 2nd robo path
-maximise 1st robo path

TC = O (N)
*/
