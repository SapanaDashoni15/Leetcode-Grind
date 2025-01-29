// class Solution {
// public:
//     int trap(vector<int>& height) {
        
//         // TC = O(N+N+N)
//         // SC = O(N+N)

//         int size = height.size();

//         vector<int> prefixMax(size);
//         prefixMax[0] = height[0];
//         for(int i = 1; i<size; i++) {
//             prefixMax[i] = max(prefixMax[i-1], height[i]);
//         }

//         vector<int> suffixMax(size);
//         suffixMax[size-1] = height[size-1];
//         for(int i = size-2; i >= 0; i--) {
//             suffixMax[i] = max(suffixMax[i+1], height[i]);
//         }

//         int total = 0;
//         for(int i=0; i<size; i++) {
//             if(height[i] < prefixMax[i] && height[i] < suffixMax[i]) {
//                 total += min(prefixMax[i], suffixMax[i]) - height[i];
//             }
//         }

//         return total;

//     }
// };



class Solution {
public:
    int trap(vector<int>& height) {
        
        // TC = O(N+N)
        // SC = O(N)
        //Optimisation : use only suffixMax , as we can have a track of leftMax while traversing
        int size = height.size();

        vector<int> suffixMax(size);
        suffixMax[size-1] = height[size-1];
        for(int i = size-2; i >= 0; i--) {
            suffixMax[i] = max(suffixMax[i+1], height[i]);
        }

        int prefixMax = INT_MIN;
        int total = 0;
        for(int i=0; i<size; i++) {
            prefixMax = max(prefixMax, height[i]);
            if(height[i] < prefixMax && height[i] < suffixMax[i]) {
                total += min(prefixMax, suffixMax[i]) - height[i];
            }
        }

        return total;

    }
};
