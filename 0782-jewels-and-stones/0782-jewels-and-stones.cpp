class Solution {
public:
    int numJewelsInStones(string jewels, string stones) {
        unordered_map<char, int> count;
        int aux = 0;
        for (char stone : stones) 
            count[stone]++;
        for (char jewel : jewels) 
            aux += count[jewel];
        return aux;
    }
};
