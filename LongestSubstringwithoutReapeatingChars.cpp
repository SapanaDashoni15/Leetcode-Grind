#include<bits/stdc++.h>
using namespace std;

int solve(string &s) {
    //brute
    int n = s.size();
    //largest string without reapting charcters
        // int maxLen = 0;
        // for (int i = 0; i < n; i++) {
        //     unordered_map<char, int> mp;
        //     int len = 0;
        //     for (int j = i; j < n; j++) {
        //         if (mp.find(s[j]) == mp.end()) {
        //             len = j-i+1;
        //             mp[s[j]]++;
        //         } else {
        //             break;
        //         }

        //         maxLen = max(maxLen, len);
        //     }
        // }

        // return maxLen;
        
        //better
        int l = 0, maxlen = 0;
        unordered_map<char, int> mp; 

        for (int r = 0; r < n; r++) {

            if (mp.find(s[r]) == mp.end()) {
                mp[s[r]] = r;
                maxlen = max(r - l + 1, maxlen);
            } 
            else {
    
                l = max(mp[s[r]]+1, l); // maybe the last pos of mp.right is prev to l 
                mp[s[r]] = r;
                maxlen = max(r - l + 1, maxlen);
            }

            
        }
        return maxlen;

}

int main() {
    string s;
    cin >> s;
    int ans = solve(s);
    cout << ans;
}
