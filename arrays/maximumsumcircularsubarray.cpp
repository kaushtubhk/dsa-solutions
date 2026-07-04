class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {

        int n = nums.size();

        int totalSum = nums[0];

        int currMax = nums[0];
        int maxSum = nums[0];

        int currMin = nums[0];
        int minSum = nums[0];

        for(int i = 1; i < n; i++) {

            totalSum += nums[i];

            // Kadane for maximum sum
            currMax = max(nums[i], currMax + nums[i]);
            maxSum = max(maxSum, currMax);

            // Kadane for minimum sum
            currMin = min(nums[i], currMin + nums[i]);
            minSum = min(minSum, currMin);
        }

        // Edge case: all elements negative
        if(maxSum < 0) {
            return maxSum;
        }

        int circularSum = totalSum - minSum;

        return max(maxSum, circularSum);
    }
};
//TC = O(n)
//SC = O(1)