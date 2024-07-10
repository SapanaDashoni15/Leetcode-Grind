class Solution {
public:
    int minOperations(vector<string>& logs) {
        //log string traversal
        //check how many parents ahead we are going
        //then return the number of parents we should go back
        
        // if we go ahead i.e 3op ++, 1st op --(only if >0) 

        //Depth counting
        int aheadOfMainFolder = 0;
        for(int i = 0 ; i < logs.size(); i++) {

            if(logs[i] == "../") {
                if(aheadOfMainFolder > 0) {
                    aheadOfMainFolder--;
                }
            }
            else if(logs[i] == "./") {

            }
            else {
                aheadOfMainFolder++;
            }

        }

        return aheadOfMainFolder;

        //real simulation with path saving
        
    }
};