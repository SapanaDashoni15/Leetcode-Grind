class Solution {
public:

    bool bs(vector<int>& arr, int n, int x) {
        int start = 0;
        int end = n-1;
        while(start <= end) {
            int mid = start + (end - start)/2;
            if(arr[mid] == x) { 
                return true;
            }
            else if(arr[mid] > x){
                end = mid - 1; 
            }
            else {
                start = mid + 1;
            }
        }
        return false;
    }

    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        int n = matrix[0].size();

        for(int i = 0; i<m; i++) {
            if(bs(matrix[i], n, target )) {
                return true;
            }
        }
        return false;
        
    }
};