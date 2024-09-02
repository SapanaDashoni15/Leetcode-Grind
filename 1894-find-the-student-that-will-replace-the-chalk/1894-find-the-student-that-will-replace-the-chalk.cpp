class Solution {
public:
    int chalkReplacer(vector<int>& chalk, int k) {
        int size = chalk.size();

        long long totalSum = 0;
        for(int i = 0; i<chalk.size(); i++) {
            totalSum += chalk[i];
        }


        k = k%totalSum;

        for(int i = 0; i < size ; i++) {
 
            if( k < chalk[i]) {
                return i;
            }
            k -= chalk[i];
        }
        return -1;
        
    }
};