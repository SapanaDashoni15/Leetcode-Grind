class Solution {
public:

    long long reqTime(vector<int>& piles, int t) {
        int n = piles.size(); 
        long long totalTime = 0;
        for(int i = 0; i < n; i++) {
            totalTime +=ceil((double)piles[i] / t); 

        }
        return totalTime;
    }  

    int minEatingSpeed(vector<int>& piles, int h) {
        int maxi = *max_element(piles.begin(), piles.end());
        int start = 1;
        int end = maxi;
        int ans = 0;
        while(start <= end) {
            int mid = start + (end - start)/2;
            long long totalTime = reqTime(piles, mid);

            if(totalTime <= h) {
                ans = mid;
                end = mid -1;
            }
            else {
                start = mid + 1;
            }
        }
        return ans;

    }
};