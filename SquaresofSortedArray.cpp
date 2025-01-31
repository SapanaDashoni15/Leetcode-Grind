class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n, 0);

        int i = n-1, l= 0, r = n-1;

        while(r >= l) {
            if( abs(nums[l]) >= abs(nums[r]) ) {
                ans[i] = nums[l]*nums[l];
                l++;
            } else {
                ans[i] = nums[r] * nums[r];
                r--;
            }
            i--;
        }
        return ans;
    }
};
