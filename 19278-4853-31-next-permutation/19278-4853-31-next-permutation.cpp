class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        // next_permutation(nums.begin(), nums.end());

        // STL implementation
        int n = nums.size();

        int ind = -1;
        for(int i = n-2; i >=0; i--) {
            if(nums[i] < nums[i+1]) {
                ind = i;
                break;
            }
        }

        if(ind == -1){
            reverse(nums.begin(), nums.end());
            return;
        } 

        for(int i = n-1; i>ind; i--) {
            if(nums[ind] < nums[i]) {
                swap(nums[i], nums[ind]);
                break;
            }
        }

        reverse(nums.begin() + ind + 1, nums.end());
        
    }
};

// tc = o(3n) sc = o(1)