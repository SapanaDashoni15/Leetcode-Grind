class Solution {
public:
    
    void fun(int start, int end, vector<char>& s) {
        if(start >= end) {
            return;
        }
        
        swap(s[start], s[end]);
        fun(start+1, end-1,s);
    }
    
    void reverseString(vector<char>& s) {
        int n = s.size()-1;
        fun(0, n,s);

    }
};