class Solution {
public:

    int solveCrossSum(vector<int> &nums, int l, int mid, int r) {
        int leftSum = INT_MIN, rightSum = INT_MIN, sum = 0;

        for(int i = mid; i >= l; i--) {
            sum += nums[i];
            leftSum = max(sum, leftSum);
        }

        sum = 0;
        for(int i = mid+1; i <= r; i++) {
            sum += nums[i];
            rightSum = max(sum, rightSum);
        }

        return leftSum + rightSum;
    }

    int solve(vector<int> &nums, int l, int r) {

        if( l == r ) return nums[l];

        int mid = (r+l)/2;

        int leftMax = solve(nums, l, mid);
        int rightMax = solve(nums, mid+1, r);
        int CrossSumMax = solveCrossSum(nums, l, mid, r);

        return max({leftMax, rightMax, CrossSumMax});
    }


    int maxSubArray(vector<int>& nums) {
        //Kadane's Algorithm
        int n =nums.size();
        // int sum = 0;
        // int maxi=INT_MIN;
        
        // for(int j =0 ; j<n ; j++){
        //     sum = sum + nums[j];
        //     maxi = max( sum , maxi);    
        //     if( sum <0){
        //         sum =0;
        //     }
        // }
        // return maxi;

        // divide and conquer

        return solve(nums, 0, n-1);
    
    }
};