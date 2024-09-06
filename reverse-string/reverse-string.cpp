class Solution {
public:
    
    void fun(int i, int n, vector<char>& s) {
        if(i >= n/2) {
            return;
        }
        
        swap(s[i], s[n-i-1]);
        fun(i+1,n,s);
    }
    
    void reverseString(vector<char>& s) {
        int n = s.size();
        fun(0, n , s);

    }
};