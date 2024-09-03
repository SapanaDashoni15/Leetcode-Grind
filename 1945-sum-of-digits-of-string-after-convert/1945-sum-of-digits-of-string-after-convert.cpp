class Solution {
public:
    int getLucky(string s, int k) {
        // store as tring to get num acces but as we are compuing change that to int
        string c = "";
        for(int i = 0; i<s.size(); i++) {

            int num = s[i]-'a'+1; // a = 0 and z = 25 in ASCII, if i want a = 1 and z = 26 , add + 1
            c += to_string(num);
        }

        int sum = 0;
        while(k>0) {
            sum = 0;
            for(int i = 0; i<c.size();i++) {
                int num = c[i]-'0';
                sum+=num;
            }
            string ss = to_string(sum);
            c = ss;
            k--;

        }
        return sum;
    }
};