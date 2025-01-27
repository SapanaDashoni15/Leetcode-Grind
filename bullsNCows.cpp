class Solution {
public:
    string getHint(string secret, string guess) {
        
        int n = secret.size();
        vector<int> freqbull(10, 0);
        vector<int> freqcow(10, 0);
        
        int bulls = 0;
        for(int i = 0; i<n; i++) {
            if(secret[i] == guess[i]) {
                bulls++;
            } else {
                freqbull[secret[i] -'0']++;
                freqcow[guess[i] -'0']++;
            }

        }
        
        int cows = 0;
        for(int i = 0; i< 10; i++) {
            cows += min(freqbull[i], freqcow[i]);
        }

        return to_string(bulls) + 'A' + to_string(cows) + 'B';

    }
};
