class Solution {
public:
    bool divideArray(vector<int>& nums) {
        unordered_set<int>sets;
        for(const auto &i:nums){
            if(sets.find(i) != sets.end())sets.erase(i);
            else sets.insert(i);
        }
        return sets.empty();
        
    }
};