// print all permutations

#include<bits/stdc++.h>
using namespace std;

void solve(vector<int> &nums, int n, vector<int> &ds, vector<vector<int>> &ans, int freq[])  {
    // base case
    if(ds.size() == nums.size() ) {
        ans.push_back(ds);
        return;
    }

    for(int i = 0; i<n; i++) {
        if(freq[i] == 0) {
            ds.push_back(nums[i]);
            freq[i] = 1;
            solve(nums, n, ds, ans, freq);
            freq[i] = 0;
            ds.pop_back();

        }
    }


}

int main() {

    vector<int> nums = {1,2,3};
    int n = 3;
    vector<int> ds;
    vector<vector<int>> ans;
    int freq[n] = {0};
    solve(nums, n, ds, ans, freq);

    for(int i = 0; i<ans.size(); i++) {
        for(int j = 0; j< ans[i].size(); j++) {
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
