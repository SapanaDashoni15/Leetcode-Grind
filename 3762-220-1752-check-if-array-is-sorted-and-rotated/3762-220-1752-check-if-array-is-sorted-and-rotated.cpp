class Solution {
public:
    bool check(vector<int>& nums) {
        // find that only one rotation point
        //if there are more than one roataion point 
        //return zero

        int n = nums.size();
        int count = 0;
        for(int i = 0; i<n-1; i++) {
            if(nums[i] <= nums[i+1]) {  // there can be duplicate elements

            }
            else {
                count++;
            }
        }

        // last element will always be smaller than or equal to first elemnt 
        //in case of LEFT roation(as here)

        if(count == 1 && nums[0] >= nums[n-1]) return true;
        else if(count == 0) return true;
        else return false;
    }
};