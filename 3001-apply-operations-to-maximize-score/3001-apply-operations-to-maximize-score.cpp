long long isPrimeScore(int num){
    long long score = 0;
    if (num % 2 == 0){
        score += 1;
        while (num % 2 == 0){
            num /= 2;
        }
    }
    for (int p = 3; p < sqrt(num); p += 2){
        if (num % p == 0){
            score += 1;
            while (num % p == 0){
                num /= p;
            }
        }
    }
    if (num > 1){
        score += 1;
    }
    return score;
}


class Solution {
public:
    int maximumScore(vector<int>& nums, int k) {
        const long long MOD = 1e9 + 7;
        vector<long long> scores;
        for (int num : nums){
            scores.push_back(isPrimeScore(num));
        }
        scores.push_back(MOD);
        int n = nums.size();
        vector<int>lefts(n, 0), rights(n, 0);
        vector<int> stack1;
        for (int i = 0; i < n; i++){
            while (!stack1.empty() && scores[i] > scores[stack1.back()]){  
                stack1.pop_back();
            }
            lefts[i] = stack1.empty() ? -1 : stack1.back();  
            stack1.push_back(i);
        }
        vector<int> stack2;
        stack2.push_back(n);
        for (int i = n - 1; i >= 0; i--){
            while (!stack2.empty() && scores[i] >= scores[stack2.back()]){ 
                stack2.pop_back();
            }
            rights[i] = stack2.empty() ? n : stack2.back();  
            stack2.push_back(i);
        }
        long long max_score = 1;
        vector<pair<int, int>> sorted_nums;
        for (int i = 0; i < n; i++){
            sorted_nums.push_back({nums[i], i});
        }
        sort(sorted_nums.rbegin(), sorted_nums.rend());
        for (auto& [num, i] : sorted_nums){
            long long count = (long long)(i - lefts[i]) * (rights[i] - i);
            max_score = (max_score * modPow(num, min((long long)k, count), MOD)) % MOD;
            if (count >= k){
                break;
            }
            k -= count;
        }
        return max_score;
    }
    long long modPow(long long base, long long exp, long long mod){
        long long res = 1;
        base = base % mod;
        while (exp > 0){
            if (exp % 2 == 1){
                res = (res * base) % mod;
            }
            exp = exp / 2;
            base = (base * base) % mod;
        }
        return res;
    }
};