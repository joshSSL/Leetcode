class Solution {
public:
    // calculates the maximum difference between the sum of
    // weights in two bags when the weights are distributed into k bags.
    long long putMarbles(vector<int>& weights, int k) {
        // by dry running the code the main thing is that
        //  if you take any distribuiton and draw a line first weight and last
        //  will be same for all so thats why delete it earlier from calcuations
        //  and if there are k bags mean k-1 line we have to draw line means
        //  distribution and by further clarification we came to know that we
        //  just have to add consecutive ele sum and at last we have to
        //  substract the max value from min value considering the k-1 pairs of distribution

        int n = weights.size(); 
        int m = n - 1; // Since we are pairing adjacent weights, we need n-1 pairs

        // Create a vector to store the sum of each pair of adjacent weights
        vector<int> pairSum(m, 0);

        // Calculate the sum of each pair of adjacent weights
        for (int i = 0; i < m; i++) {
            pairSum[i] =
                weights[i] +
                weights[i + 1]; 
        }

        sort(pairSum.begin(), pairSum.end());

        long long maxSum = 0; 
        long long minSum = 0; 

        // Calculate the minimum and maximum sum by considering k-1 pairs
        // We iterate from 0 to k-2 (since we need k-1 pairs) and add the
        // smallest pairs to minSum and the largest pairs to maxSum
        for (int i = 0; i < k - 1; i++) {
            minSum += pairSum[i];         
            maxSum += pairSum[m - 1 - i]; // Add the largest pair to maxSum
        }

        return maxSum - minSum;
    }
};