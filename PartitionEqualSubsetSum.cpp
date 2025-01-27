class Solution {
public:
    bool solve(int ind, int k, vector<int>& arr, vector<vector<int>>& dp) {
        if (k == 0) return true; 
        if (ind == 0) return arr[0] == k; 

        if (dp[ind][k] != -1) return dp[ind][k]; 

       
        bool notTake = solve(ind - 1, k, arr, dp);
        bool take = false;
        if (arr[ind] <= k) {
            take = solve(ind - 1, k - arr[ind], arr, dp);
        }

        return dp[ind][k] = take || notTake;
    }

    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if (sum % 2 != 0) return false;

        int target = sum / 2;
        vector<vector<int>> dp(n, vector<int>(target + 1, -1)); 
        return solve(n - 1, target, nums, dp);
    }
};
