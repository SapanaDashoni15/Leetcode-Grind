class Solution {
public:

    bool isPossible(vector<int>& arr, int days, int m, int k) {
        int n = arr.size();
        int numOfB = 0;
        int cnt = 0;
        for(int i = 0; i<n; i++) {
            if(arr[i] <= days) {
                cnt++;
            }
            else {
                numOfB += cnt/k;
                cout << numOfB << endl;
                cnt = 0;
            }
        }
        numOfB += cnt/k;
        // cout << numOfB << endl;
        if(numOfB >= m) return true;
        else return false;
    }

    int minDays(vector<int>& bloomDay, int m, int k) {
        int n = bloomDay.size();
        if( n < (long)m*k) return -1;

        int mini = *min_element(bloomDay.begin(), bloomDay.end());
        int maxi = *max_element(bloomDay.begin(), bloomDay.end());
        cout << mini << " " << maxi << endl;
        //take days range
        // for(int i = mini; i<= maxi; i++) {
        //     if(isPossible(bloomDay, i, m, k)) {
        //         return i;
        //     }
        // }
        // return -1;

        //optimised
        int ans = maxi;
        while(mini <= maxi) {
            int mid = mini + ( maxi - mini)/2;
            if(isPossible(bloomDay, mid, m ,k)) {
                ans = mid;
                maxi = mid - 1;
            } else {
                mini = mid + 1;
            }
        }
        return ans;
    }
};