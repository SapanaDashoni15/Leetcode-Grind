class Solution {
public:

    bool isSubset(unordered_map<char, int>& mp2, unordered_map<char, int>& mp1) {
        for (auto& [ch, freq] : mp2) {
            if (mp1[ch] < freq) {
                return false; 
            }
        }
        return true;
    }

    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
        unordered_map<char, int> mp2;  
        for (const string& word : words2) {
            unordered_map<char, int> tempFreq;
            for (char c : word) {
                tempFreq[c]++;
            }
            for (auto& [ch, freq] : tempFreq) {
                mp2[ch] = max(mp2[ch], freq);
            }
        }

        vector<string> result;

        for (const string& word : words1) {
            unordered_map<char, int> mp1;
            for (char c : word) {
                mp1[c]++;
            }

            if (isSubset(mp2, mp1)) {
                result.push_back(word);
            }
        }

        return result;
    }
};
