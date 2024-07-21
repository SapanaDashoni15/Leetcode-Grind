class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        //two pointer approach
        //for element in original array, unique elements

        int i = 1,j = 1;
        for(int i = 1; i<nums.size(); i++) {
             if(nums[i] != nums[i-1]) {
                nums[j] = nums[i];
                j++;
             }
        }
        return j;
    }
};