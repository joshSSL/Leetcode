class Solution {
public:
    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
        vector<string> ans;

        vector<int> freqWord2 (26, 0);
        for(int i = 0; i < words2.size(); i++) {
            vector<int> temp (26, 0);
            for(char ch: words2[i]) {
                temp[ch - 'a']++;
                freqWord2[ch - 'a'] = max(freqWord2[ch - 'a'], temp[ch - 'a']);
            }
        }

        for(int i = 0; i < words1.size(); i++) {
            vector<int> temp (26, 0);
            for(char c: words1[i]) {
                temp[c - 'a']++;
            }

            bool check = true;

            for(int j = 0; j < 26; j++) {
                if(temp[j] < freqWord2[j]) {
                    check = false;
                    break;
                }
            }
            if(check) {
                ans.push_back(words1[i]);
            }
        }
         
        return ans;
    }
};