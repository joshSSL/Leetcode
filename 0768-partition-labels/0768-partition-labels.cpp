class Solution {
public:
    vector<int> partitionLabels(string s) {
        vector<int> last(26, -1); 
        for (int i = 0; i < s.size(); i++) {
            last[s[i] - 'a'] = i; 
        }

        vector<int> ans;
        int i = 0;
        while (i < s.size()) {
            int j = last[s[i] - 'a'];
            int k = i;
            
            while (k < j) { 
                if (last[s[k] - 'a'] > j) { 
                    j = last[s[k] - 'a'];
                }
                k++;
            }

            ans.push_back(j - i + 1); 
            i = j + 1; 
        }

        return ans;
    }
};